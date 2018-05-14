

TreeNode * newNODE(int type)
{
	TreeNode * T = (TreeNode *)malloc(sizeof(TreeNode));
	T->NodeType = type;
	return T;
}


TreeNode * newINT(int value)
{
	Int * I = (Int *)malloc(sizeof(Int));
	I->NodeType = INT_VAL;
	I->i = value;
	return (TreeNode *) I;
}

TreeNode * newDOUBLE(double value)
{
	Double * D = (Double *)malloc(sizeof(Double));
	D->NodeType = DOUBLE_VAL;
	D->d = value;
	return (TreeNode *) D;
}

TreeNode * newBOOL(int value)
{
	Bool * B = (Bool *)malloc(sizeof(Bool));
	B->NodeType = BOOL_VAL;
	B->b = value;
	return (TreeNode *) B;
}

TreeNode * newSTRING(char* value)
{
	String * S = (String *)malloc(sizeof(String));
	S->NodeType = STRING_VAL;
	strcpy(S->s, value);
	return (TreeNode *) S;
}

TreeNode * newCHAR(char value)
{
	Char * C = (Char *)malloc(sizeof(Char));
	C->NodeType = CHAR_VAL;
	C->c = value;
	return (TreeNode *) C;
}

TreeNode * newID(char * name)   // used when ID appears in expressions as RHS
{
	Id * I = (Id *)malloc(sizeof(Id));
	I->NodeType = ID;
	strcpy(I->name, name);
	return (TreeNode *) I;
}

TreeNode * newEXP(int type, TreeNode * left, TreeNode * right)
{
	Exp * E = (Exp *)malloc(sizeof(Exp));
	E->NodeType = type;
	E->rhs = right;
	E->lhs = left;
	return (TreeNode *) E;
}

TreeNode * newSTMNT(int num,...)
{
	va_list valist;
	va_start(valist, num);
	Stmnt * S = (Stmnt *)malloc(sizeof(Stmnt));
	int type = va_arg(valist, int);


	if(type == ASSI_STMNT)
	{
		char * ID_name = va_arg(valist, char*);
		TreeNode * rhs = va_arg(valist, TreeNode*);
		va_end(valist);

		Id * I = (Id *)malloc(sizeof(Id));
		strcpy(I->name, ID_name);
		I->NodeType = ID;

		S->NodeType = ASSI_STMNT;
		S->Id = (TreeNode *) I;
		S->rhs = rhs;
		S->con = 0;
		strcpy(S->type, "");
		printf("dddddddddddddddddddddddddddddd name = %s\n", ((Id*)(S->Id))->name);
		return (TreeNode*)S;
	}
	else if(type == DECL_STMNT)
	{
		char * var_type = va_arg(valist, char*);
		char * ID_name = va_arg(valist, char*); 
		va_end(valist);

		Id * I = (Id *)malloc(sizeof(Id));
		strcpy(I->name, ID_name);
		I->NodeType = ID;

		S->NodeType = DECL_STMNT;
		S->Id = (TreeNode *) I;
		S->rhs = NULL;
		S->con = 0;
		strcpy(S->type, var_type);
		return (TreeNode*)S;
	}
	else if(type == DECL_ASSI_STMNT)
	{
		char * var_type = va_arg(valist, char*);
		TreeNode * astmnt = va_arg(valist, TreeNode*);
		va_end(valist);

		strcpy( ((Stmnt*)astmnt)->type, var_type);
		((Stmnt*)astmnt)->NodeType = DECL_ASSI_STMNT;
		return astmnt;
	}
	else if(type == CONST_DECL_STMNT) // constant declaration
	{
		int con = va_arg(valist, int);
		TreeNode * dstmnt = va_arg(valist, TreeNode*);
		va_end(valist);

		((Stmnt*)dstmnt)->NodeType = CONST_DECL_STMNT;
		((Stmnt*)dstmnt)->con = 1;
		return dstmnt;
	}
	else //empty
	{
		S->NodeType = EMPTY_STMNT;
		S->Id = NULL;
		S->rhs = NULL;
		S->con = 0;
		strcpy(S->type, "");
		return (TreeNode*)S;
	}

	
}


/*
TreeNode * newASTMNT(char * type, char * id, TreeNode * rhs)
{
	
	Id * I = (Id *)malloc(sizeof(Id));
	I->name = id;
	I->NodeType = ID;

	Stmnt1 * S = (Stmnt1 *)malloc(sizeof(Stmnt1));
	S->NodeType = STMNT1;
	S->Id = (TreeNode *) I;
	S->rhs = rhs;

	return (TreeNode *) S;
}


TreeNode * newDSTMNT(char * type, int con, TreeNode * stmnt)
{
	char * ID_name =  stmnt->Id->name;
	symbol s = get_symbol(table, ID_name);
	if (con == 0)  // stmnt will be a declaration statement
	{		
		if(strcmp(type, "int") == 0)
			s.type = 1;
		else if(strcmp(type, "double"))
			s.type = 2;
		else if(strcmp(type, "bool"))
			s.type = 3;
		else if(strcmp(type, "char"))
			s.type = 4;
		else			// string
			s.type = 5;
	}
	else
	{
		s.con = 1;
	}
	update_symbol(table, s);

	return  stmnt;
}

*/
TreeNode * newFLOW(int type, TreeNode* cond, TreeNode* if_brnch, TreeNode* el_brnch)
{
	Flow * F = (Flow *)malloc(sizeof(Flow));
	F->NodeType = type;
	F->cond = cond;
	F->if_brnch = if_brnch;
	F->els_brnch = el_brnch;

	return (TreeNode *) F;
}


TreeNode * newFOR(TreeNode * decl_list, TreeNode * cond, TreeNode * assi_list, TreeNode * body)
{
	For * F = (For *)malloc(sizeof(For));
	F->NodeType = FOR;
	F->decl_list = decl_list;
	F->cond = cond;
	F->assi_list = assi_list;
	F->body = body;

	return (TreeNode *) F;
}


TreeNode * newSWITCH(TreeNode * exp, TreeNode * sw_body)
{
	Switch * S = (Switch *)malloc(sizeof(Switch));
	S->NodeType = SWITCH;
	S->exp = exp;
	S->body = sw_body;

	return (TreeNode *) S;
}


TreeNode * newCASE(int type, TreeNode * c_exp, TreeNode * c_list)
{
	Case * C = (Case *)malloc(sizeof(Case));
	C->NodeType = type;
	C->case_exp = c_exp;
	C->case_list = c_list;

	return (TreeNode *) C;
}


TreeNode * newSBODY( TreeNode * case_block, TreeNode * sw_body)
{
	Swbody * S = (Swbody *)malloc(sizeof(Swbody));
	S->NodeType = SWBODY;
	S->case_block = case_block;
	S->sbody = sw_body;

	return (TreeNode *) S;
}


TreeNode * newALIST(TreeNode * astmnt, TreeNode * alist)
{
	Assi_list * A = (Assi_list *)malloc(sizeof(Assi_list));
	A->NodeType = ASSI_LIST;
	A->astmnt = astmnt;   
	A->alist = alist;

	return (TreeNode *) A;
}


TreeNode * newDLIST(TreeNode * alist)
{
	Decl_list * D = (Decl_list *)malloc(sizeof(Decl_list));
	D->NodeType = DECL_LIST;
	D->alist = alist;

	return (TreeNode *) D;
}


TreeNode * newLIST(TreeNode * st, TreeNode * l)
{
	List * L = (List *)malloc(sizeof(List));
	L->NodeType = LIST;
	L->statement = st;
	L->list = l;

	return (TreeNode *) L;
}

//--------------------------------------semantics functions ---------------------------------------


void print_symbol(Symbol s)
{
	printf("name = %s\n", s.name);
	printf("defline = %d\n", s.def_line);
	printf("init_line = %d\n", s.init_line);
	printf("type = %s\n", s.type);
	printf("con = %d\n", s.con);
}


void decl_stmnt_semantics(TreeNode * stmnt)
{
	Id * I = (Id*)(((Stmnt*)stmnt)->Id);
	Symbol s = get_symbol(I->name);

	//semantics checking
	if(s.def_line != not_defined)   // if previously defined
	{
		fprintf(sem_errors_file, "An identifier \"%s\" at line %d is previously defined at line %d\n",I->name, yylineno, s.def_line);
	}


	//add symbol to table
	s.def_line = yylineno;
	strcpy(s.type, ((Stmnt*)stmnt)->type);
	
	if(strcmp(s.name, "") == 0) // if symbol isn't inserted before
	{	
		strcpy(s.name, I->name);
		add_symbol(s);
	}
	else
	{
		update_symbol(s);
	}

}


void assi_stmnt_semantics(TreeNode * stmnt)
{
	Id * I = (Id*)(((Stmnt*)stmnt)->Id);
	Symbol s = get_symbol(I->name);

	//check semantics
	if(s.def_line == not_defined)
	{
		fprintf(sem_errors_file, "Use of undefined identifier \"%s\" at line %d\n",I->name, yylineno);
	}
	
	if(s.con == 1)  // if it's a constant
	{
		fprintf(sem_errors_file, "Const Identifier \"%s\" can't be assigned a value at line %d\n",I->name, yylineno);
	}
	else
		s.init_line = yylineno;

	//3 -checking type with type of expression latter

	//add symbol to table
	
	

	if(strcmp(s.name, "") == 0) // if symbol isn't inserted before
	{
		strcpy(s.name, I->name);
		add_symbol(s);
	}
	else
	{
		update_symbol(s);
	}
}


void decl_assi_stmnt_semantics(TreeNode * stmnt)
{
	Id * I = (Id*)(((Stmnt*)stmnt)->Id);
	Symbol s = get_symbol(I->name);

	//semantics checking
	if(s.def_line != not_defined)   // if previously defined
	{
		fprintf(sem_errors_file, "An identifier \"%s\" at line %d is previously defined at line %d\n",I->name, yylineno, s.def_line);
	}
	// add expression semantics latter

	//add symbol to table
	s.init_line = yylineno;
	s.def_line = yylineno;
	strcpy(s.type, ((Stmnt*)stmnt)->type);

	if(strcmp(s.name, "") == 0) // if symbol isn't inserted before
	{
		strcpy(s.name, I->name);
		add_symbol(s);
	}
	else
		update_symbol(s);

}



void const_decl_stmnt_semantics(TreeNode * stmnt)
{

	Id * I = (Id*)(((Stmnt*)stmnt)->Id);
	Symbol s = get_symbol(I->name);

	//semantics checking
	if(s.def_line != not_defined)   // if previously defined
	{
		fprintf(sem_errors_file, "An identifier \"%s\" at line %d is previously defined at line %d\n",I->name, yylineno, s.def_line);
	}

	// checking type of expression && expression should be variable free

	// adding symbol in table
	s.def_line = yylineno;
	s.init_line = yylineno;
	strcpy(s.type, ((Stmnt*)stmnt)->type);
	s.con = 1;
	if(strcmp(s.name, "") == 0)
	{
		strcpy(s.name, I->name);
		add_symbol(s);
	}
	else
		update_symbol(s);

}


void id_semantics(TreeNode * id)
{
	Id* I = (Id*)id;
	Symbol s = get_symbol(I->name);

	//check semantics
	if(s.def_line == not_defined)
	{
		fprintf(sem_errors_file, "Use of undefined identifier \"%s\" at line %d\n",I->name, yylineno);
	}
	else if(s.init_line == not_initialized)
	{			
		fprintf(sem_errors_file, "Use of uninitialzed identifier \"%s\" at line %d\n",I->name, yylineno);
	}

	//add to symbol table
	if(strcmp(s.name, "") == 0)
	{
		strcpy(s.name, I->name);
		add_symbol(s);
	}
}


/*
void extend_table()
{
	
	table = malloc(sizeof(Sym_table));
	table->count = 0;
	table->symbols = malloc(sizeof(Symbol) * bucket_size);
	table->next = NULL;
	
}
*/


void add_symbol(Symbol S)
{

	strcpy(table.symbols[table.count].name, S.name);
	table.symbols[table.count].def_line = S.def_line;
	table.symbols[table.count].init_line = S.init_line;
	strcpy(table.symbols[table.count].type, S.type);
	table.symbols[table.count].con = S.con;
	table.count++;

		//extend_table();
/*	
	// reach the last bucket

	Sym_table * current = table;

	while(current->next != NULL)
		{
			printf("STUPID\n");
			current = current->next;
		}
	

	if(current->count == bucket_size)  // if last bucket is full
	{
		extend_table(current->next);
		current = current->next;
	}

	strcpy(current->symbols[current->count].name, S.name);
	current->symbols[current->count].def_line = S.def_line;
	current->symbols[current->count].init_line = S.init_line;
	strcpy(current->symbols[current->count].type, S.type);
	current->symbols[current->count].con = S.con;
	current->count++;
*/
}


Symbol get_symbol(char * name)
{
	Symbol S;
	strcpy(S.name, "");
	S.def_line = not_defined;
	S.init_line = not_initialized;
	strcpy(S.type, "");
	S.con = 0;


	for(int i=0; i<table.count; i++)
	{
		if(strcmp(name, table.symbols[i].name) == 0)
		{
			strcpy(S.name, name);
			S.def_line = table.symbols[i].def_line;
			S.init_line = table.symbols[i].init_line;
			strcpy(S.type, table.symbols[i].type);
			S.con = table.symbols[i].con;
			return S;
		}
	}

/*
	Sym_table * current = table;
	while(current!= NULL)
	{
		for(int i=0; i<current->count; i++)
		{
			if(strcmp(name, current->symbols[i].name) == 0)
			{
				strcpy(S.name, name);
				S.def_line = current->symbols[i].def_line;
				S.init_line = current->symbols[i].init_line;
				strcpy(S.type, current->symbols[i].type);
				S.con = current->symbols[i].con;
				return S;
			}
		}
		current = current->next;
	}
	*/
	return S;
}

int update_symbol(Symbol s)
{

	for(int i=0; i<table.count; i++)
	{
		if(strcmp(s.name, table.symbols[i].name) == 0)
		{
			table.symbols[i].def_line = s.def_line;
			table.symbols[i].init_line = s.init_line;
			strcpy(table.symbols[i].type, s.type);
			table.symbols[i].con = s.con;
			return 1;
		}
	}
	/*
	while(table != NULL)
	{
		for(int i=0; i<table->count; i++)
		{
			if(strcmp(s.name, table->symbols[i].name) == 0)
			{
				strcpy(table->symbols[i].name, s.name);
				table->symbols[i].def_line = s.def_line;
				table->symbols[i].init_line = s.init_line;
				strcpy(table->symbols[i].type, s.type);
				table->symbols[i].con = s.con;
				return 1;
			}
		}
	}
	*/
	return 0;
}

void generate_symbols_file()
{
	FILE * S = fopen("symbols.txt", "w");
	

	for(int i=0; i<table.count; i++)
	{
		fprintf(S, "var: %s\n", table.symbols[i].name);
		fprintf(S, "def_line: %d\n", table.symbols[i].def_line);
		fprintf(S, "init_line: %d\n", table.symbols[i].init_line);
		fprintf(S, "type: %s\n", table.symbols[i].type);
		fprintf(S, "Constant: %d\n", table.symbols[i].con);
		fprintf(S, "---------------------------------------------\n");
	}

	/*
	while(table != NULL)
	{
		for(int i=0; i< table->count; i++)
		{
			fprintf(S, "var: %s\n", table->symbols[i].name);
			fprintf(S, "def_line: %d\n", table->symbols[i].def_line);
			fprintf(S, "init_line: %d\n", table->symbols[i].init_line);
			fprintf(S, "---------------------------------------------\n");
		}
		table = table->next;
	}
	*/
	fclose(S);
}


