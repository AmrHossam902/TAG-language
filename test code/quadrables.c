#include <stdio.h>
#include "./structures.h"

//Don't forget to close the file
FILE *f = fopen("file.txt", "w");
if (f == NULL)
{
    printf("Error opening file!\n");
    exit(1);
}
int tmp_counter = 1;    //counter for the temp variables
int loop_counter = 1;    //counter for the loop variables

void analyzeList (TreeNode * root, char * c){

    List * code = (List *) root;
    while (code->list != NULL){
        analyzeStmnt(code->statement,c);
        root = code->list;
    }
}

void analyzeStmnt(TreeNode * stmnt, char * c){

    if (stmnt->NodeType == EMPTY_STMNT){
        //Do nothing, I guess
    }else if (stmnt->NodeType == FOR){
        analyzeFor(stmnt);
    }else if (stmnt->NodeType == IF || stmnt->NodeType == WHILE || stmnt->NodeType == REPEAT){
        analyzeFlow(stmnt);
    }else if (stmnt->NodeType == SWITCH){
        analyzeSwitch(stmnt);
    }else if (stmnt->NodeType == BREAK){
        analyzeBreak(c);
    }else{
        //the first four types
        analyzeAssignStmnt(stmnt);
    }
}

void analyzeAssignStmnt( TreeNode * stmnt){

    Stmnt * s = (Stmnt * ) stmnt;
    char[50] rhs = analyzeExp(s->rhs);
    fprintf(f,"%s = %s\n",s->Id,rhs);
}

char * analyzeExp(TreeNode * stmnt){

    if (stmnt->NodeType == BOOL_VAL){
        Bool * BoolStmnt = (Bool * ) stmnt;
        int b = BoolStmnt->b;
        char v[50];
        itoa(b,v,10);
        return v;
    }else if (stmnt->NodeType == INT_VAL){
        Int * IntStmnt = (Int * ) stmnt;
        int i = IntStmnt->i;
        char v[50];
        itoa(i,v,10);
        return v;
    }else if (stmnt->NodeType == DOUBLE_VAL){
        Double * DoubleStmnt = (Double * ) stmnt;
        double d = DoubleStmnt->d;
        char v[50];
        dtoa(d,v,10);
        return v;
    }else if (stmnt->NodeType == STRING_VAL){
        String * StringStmnt = (String * ) stmnt;
        char v[50] = StringStmnt->s;
        return v;
    }else if (stmnt->NodeType == ID){
        Id * IdStmnt = (Id * ) stmnt;
        char v[50] = IdStmnt->name;
        return v;
    }else {
        Exp * ExpStmnt = (Exp * ) stmnt;
        char lhs[50] = analyzeExp(ExpStmnt->lhs);
        if (ExpStmnt->NodeType == EE){
            char op[2] = "==";
        }else if (ExpStmnt->NodeType == NE){
            char op[2] = "==";
        }else if (ExpStmnt->NodeType == LT){
            char op = '<';
        }else if (ExpStmnt->NodeType == GT){
            char op = '>';
        }else if (ExpStmnt->NodeType == LE){
            char op[2] = "<=";
        }else if (ExpStmnt->NodeType == GE){
            char op[2] = ">=";
        }else if (ExpStmnt->NodeType == AND){
            char op = '&';
        }else if (ExpStmnt->NodeType == OR){
            char op = '|';
        }else if (ExpStmnt->NodeType == XOR){
            char op = '^';
        }else if (ExpStmnt->NodeType == UMINUS){
            char op = '-';
        }else if (ExpStmnt->NodeType == NOT){
            char op = '!';
        }else {
            char op = (char) ExpStmnt->NodeType;
        }
        char c[3];
        itoa(tmp_counter,c,10);
        tmp_counter++;
        char v[50];
        v[0] = 'T';
        v[1] = c[0];
        v[2] = c[1];
        v[3] = c[2];
        if (ExpStmnt->rhs == NULL){
            fprintf(f, "%s = %s %s\n",v,op,lhs);
        }else {
            char rhs[50] = analyzeExp(ExpStmnt->rhs);    
            fprintf(f, "%s = %s %s %s\n",v,lhs,op,rhs);
        }
        return v;
    }
}

void analyzeFlow(TreeNode * stmnt){

    Flow * FlowStmnt = (Flow * ) stmnt;
    if (FlowStmnt->NodeType == IF){
        char c[3];
        itoa(loop_counter,c,10);
        loop_counter++;
        analyzeExp(FlowStmnt->cond);
        fprintf(f,"JZ LOOP%s\n",c);                    //zero flag: condition false
        analyzeList(FlowStmnt->if_brnch,NULL);
        if (FlowStmnt->els_brnch != NULL){
            char c1[3];
            itoa(loop_counter,c1,10);
            loop_counter++;
            fprintf(f,"JMP LOOP%s\n",c1);             //loop c1 is at the end of else, it prevents the ip to enter the else block
            fprintf(f,"LOOP%s : ",c);
            analyzeList(FlowStmnt->els_brnch,NULL);
            fprintf(f,"LOOP%s : ",c1);
        }else{
            fprintf(f,"LOOP%s : ",c);
        }
    }else if (FlowStmnt->NodeType == WHILE){
        char c[3];
        itoa(loop_counter,c,10);
        loop_counter++;
        fprintf(f,"LOOP%s : ",c);              //loop c at the beginnig of the while block
        char c1[3];
        itoa(loop_counter,c1,10);
        loop_counter++;
        analyzeExp(FlowStmnt->cond);
        fprintf(f,"JZ LOOP%s\n",c1);              //loop c1 outside the loop block. it helps in exiting the loop 
        analyzeList(FlowStmnt->if_brnch,c1);
        fprintf(f,"JMP LOOP%s\n",c);
        fprintf(f,"LOOP%s : ",c1);
    }else{
        char c[3];
        itoa(loop_counter,c,10);
        loop_counter++;
        char c1[3];
        itoa(loop_counter,c1,10);
        loop_counter++;
        fprintf(f,"LOOP%s : ",c);              //loop c at the beginning of the repeat block.
        analyzeList(FlowStmnt->if_brnch,c1);
        analyzeExp(FlowStmnt->cond);
        fprintf(f,"JZ LOOP%s\n",c);
        fprintf(f,"LOOP%s : ",c1);              //loop c1 at the end of the repeat block.
    }
}

void analyzeFor(TreeNode * stmnt){

    For * ForStmnt = (For * ) stmnt;
    analyzeDecList(ForStmnt->decl_list);
    char c[3];
    itoa(loop_counter,c,10);
    loop_counter++;
    fprintf(f,"LOOP%s : ",c);                   //loop c at the beginning of the for block.
    analyzeExp(ForStmnt->cond);
    char c1[3];
    itoa(loop_counter,c1,10);
    loop_counter++;
    fprintf(f,"JZ LOOP%s\n",c1);                   //loop c1 outside the for block. it helps in exiting the loop 
    analyzeList(ForStmnt->body,c1);
    analyzeAssignList(ForStmnt->assi_list);
    fprintf(f,"JMP LOOP%s\n",c);
    fprintf(f,"LOOP%s : ",c1);
}

void analyzeDecList(TreeNode * stmnt){

    Decl_list * DecList = (Decl_list * ) stmnt;
    analyzeAssignList(DecList->alist);
}

void analyzeAssignList(TreeNode * stmnt){

    Assi_list * AssigList = (Assi_list * ) stmnt;
    while (AssigList != NULL){
        analyzeAssignStmnt(AssigList->astmnt);
        AssigList = AssigList->alist;
    }
}

void analyzeBreak(char * c){

    fprintf(f,"JMP LOOP%s\n",c);
}

void analyzeSwitch(TreeNode * stmnt){
    
    Switch * SwitchStmnt = (Switch * ) stmnt;
    Id * IDStmnt = (Id * ) SwitchStmnt->exp;
    char c[3];
    itoa(loop_counter,c,10);
    loop_counter++;
    analyzeSBody(SwitchStmnt->body,IDStmnt->name,c);
}

void analyzeSBody(TreeNode * stmnt, char * ID, char * c){

    Swbody * SWBody = (Swbody * ) stmnt;
    while (SWBody != NULL){
        analyzeCase(SWBody->case_block,ID,c);
        SWBody = SWBody->sbody;
    }
}

void analyzeCase(TreeNode * stmnt, char * ID, char * c1){

    Case * CaseStmnt = (Case * ) stmnt;
    if (CaseStmnt->case_exp != NULL){
        Id * IDStmnt = (Id * ) CaseStmnt->case_exp;
        fprintf(f,"CMPEQ %s , %s\n",ID,IDStmnt->name);          //compare both are equal or not
        char c[3];
        itoa(loop_counter,c,10);
        loop_counter++;        
        fprintf(f,"JZ LOOP%s\n",c);
        analyzeList(CaseStmnt->case_list,c1);
        fprintf(f,"JMP LOOP%s\n",c1);                           //exit switch
        fprintf(f,"LOOP%s : ",c);
    }else {
        analyzeList(CaseStmnt->case_list,c1);
        fprintf(f,"LOOP%s : ",c1);
    }
}