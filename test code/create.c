

TreeNode * newNODE(int type)
{
	TreeNode * T = (TreeNode *)malloc(sizeof(TreeNode));
	T->NodeType = type;
	return T;
}


TreeNode * newINT(int value, int linenum)
{
	Int * I = (Int *)malloc(sizeof(Int));
	I->NodeType = INT_VAL;
	I->i = value;
	I->linenum = linenum;
	return (TreeNode *) I;
}

TreeNode * newDOUBLE(double value, int linenum)
{
	Double * D = (Double *)malloc(sizeof(Double));
	D->NodeType = DOUBLE_VAL;
	D->d = value;
	D->linenum = linenum;
	return (TreeNode *) D;
}

TreeNode * newBOOL(int value, int linenum)
{
	Bool * B = (Bool *)malloc(sizeof(Bool));
	B->NodeType = BOOL_VAL;
	B->b = value;
	B->linenum = linenum;
	return (TreeNode *) B;
}

TreeNode * newSTRING(char* value, int linenum)
{
	String * S = (String *)malloc(sizeof(String));
	S->NodeType = STRING_VAL;
	S->linenum = linenum;
	strcpy(S->s, value);
	return (TreeNode *) S;
}

/*
TreeNode * newCHAR(char value, int linenum)
{
	Char * C = (Char *)malloc(sizeof(Char));
	C->NodeType = CHAR_VAL;
	C->c = value;
	C->linenum = linenum;
	return (TreeNode *) C;
}*/

TreeNode * newID(char * name, int linenum)   // used when ID appears in expressions as RHS
{
	Id * I = (Id *)malloc(sizeof(Id));
	I->NodeType = ID;
	I->linenum = linenum;
	strcpy(I->name, name);
	return (TreeNode *) I;
}

TreeNode * newEXP(int type, TreeNode * left, TreeNode * right, int linenum)
{
	Exp * E = (Exp *)malloc(sizeof(Exp));
	E->NodeType = type;
	E->linenum = linenum;
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
		I->linenum = yylineno;

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
		I->linenum = yylineno;
		
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


TreeNode * newDLIST(char* type, TreeNode * alist)
{
	Decl_list * D = (Decl_list *)malloc(sizeof(Decl_list));
	D->NodeType = DECL_LIST;
	D->alist = alist;

	TreeNode * current = alist;
	while(current != NULL)
	{
		strcpy(((Stmnt*)(((Assi_list *)current)->astmnt))->type, type);
		current = (TreeNode*) (((Assi_list*)current)->alist);
	}

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


int convert_chart_to_intt(char* buff)
{
	if( strcmp(buff, "int")==0 )
		return INT_VAL;
	if( strcmp(buff, "double")==0 )
		return DOUBLE_VAL;
	if( strcmp(buff, "bool")==0 )
		return BOOL_VAL;
	if( strcmp(buff, "string")==0 )
		return STRING_VAL;
	return UNKNOWN;
}

int exp_semantics(TreeNode* exp)
{
	
	if(exp->NodeType == INT_VAL || exp->NodeType == DOUBLE_VAL || exp->NodeType == BOOL_VAL || exp->NodeType == STRING_VAL)
	{
		fprintf(sem_errors_file, "NODE T = %d\n", exp->NodeType);
		return exp->NodeType;
	}
	if(exp->NodeType == ID)
	{
		Symbol s = get_symbol(((Id*)exp)->name);
		
		if( strcmp(s.type, "int") == 0 )
			return INT_VAL;

		if( strcmp(s.type, "double") == 0 )
			return DOUBLE_VAL;

		if( strcmp(s.type, "bool") == 0 )
			return BOOL_VAL;

		if( strcmp(s.type, "string") == 0 )
			return STRING_VAL;

		fprintf(sem_errors_file, "ID name = %s\n", ((Id*)exp)->name);
		fprintf(sem_errors_file, "Identifier with unknown type at line %d integer assumed\n", ((Id*)exp)->linenum);
		return UNKNOWN;
	}

	if(exp->NodeType == UMINUS)
	{
		int lhs = exp_semantics( ((Exp*)exp)->lhs );

		if(lhs == STRING_VAL)
		{
			fprintf(sem_errors_file, "unary minus can't be applied to a string operand at line %d\n",((Exp*)exp)->linenum );
			return UNKNOWN;
		}
		else if(lhs == BOOL_VAL)
		{
			fprintf(sem_errors_file, "unary minus can't be applied to a bool operand at line %d\n",((Exp*)exp)->linenum );
			return UNKNOWN;
		}
		else
			return lhs;
	}

	if(exp->NodeType == NOT)
	{
		int lhs = exp_semantics( ((Exp*)exp)->lhs );

		if(lhs == UNKNOWN)
			return UNKNOWN;
		if(lhs != BOOL_VAL)
		{
			fprintf(sem_errors_file, " \'!\' operator can't be applied to a non bool operand at line %d\n",((Exp*)exp)->linenum );
			return UNKNOWN;
		}

		return BOOL_VAL;
	}

	if(exp->NodeType == AND || exp->NodeType == OR || exp->NodeType == XOR)
	{
		int lhs = exp_semantics( ((Exp*)exp)->lhs );
		int rhs = exp_semantics( ((Exp*)exp)->rhs );

		if(lhs == UNKNOWN || rhs == UNKNOWN)
		{
			printf("Logical operator can't be applied to unknown type operand at line %d\n", ((Exp*)exp)->linenum );
			return UNKNOWN;
		}

		if(lhs != BOOL_VAL)
			fprintf(sem_errors_file, " Non bool operand found on LHS of a logical operator at line %d\n",((Exp*)exp)->linenum );

		if(rhs != BOOL_VAL)
			fprintf(sem_errors_file, " Non bool operand found on RHS of a logical operator at line %d\n",((Exp*)exp)->linenum );
		return BOOL_VAL;
	}


	if(exp->NodeType == GT || exp->NodeType == GE ||exp->NodeType == LT ||exp->NodeType == LE || exp->NodeType == EE || exp->NodeType == NE)
	{
		int lhs = exp_semantics( ((Exp*)exp)->lhs );
		int rhs = exp_semantics( ((Exp*)exp)->rhs );


		char buff[3];
		if(exp->NodeType == GT)
			strcpy(buff, ">");
		else if(exp->NodeType == GE )
			strcpy(buff, ">=");
		else if(exp->NodeType == LT )
			strcpy(buff, "<");
		else if(exp->NodeType == LE)
			strcpy(buff, "<=");
		else if(exp->NodeType == EE)
			strcpy(buff, "==");
		else
			strcpy(buff, "!=");


		if(lhs == UNKNOWN)
		{
			fprintf(sem_errors_file, "LHS operand of \"%s\" is of unknown type at line%d \n", buff ,((Exp*)exp)->linenum );
			return UNKNOWN;
		}

		if(rhs == UNKNOWN)
		{
			fprintf(sem_errors_file, "RHS operand of \"%s\" is of unknown type at line%d \n", buff ,((Exp*)exp)->linenum );
			return UNKNOWN;
		}		



		if( (lhs != INT_VAL && lhs != DOUBLE_VAL) && (exp->NodeType != EE && exp->NodeType != LE) )  // if >, >=, < , <=
		{
			fprintf(sem_errors_file, " Non Numerical operand can't be used on LHS of \"%s\" operator at line %d\n", buff, ((Exp*)exp)->linenum );
			return UNKNOWN;
		}
		if( (rhs != INT_VAL && lhs != DOUBLE_VAL) && (exp->NodeType != EE && exp->NodeType != LE) )  // if >, >=, < , <=
		{
			fprintf(sem_errors_file, " Non Numerical operand can't be used on RHS of \"%s\" operator at line %d\n", buff, ((Exp*)exp)->linenum );
			return UNKNOWN;
		}


		if(exp->NodeType == EE || exp->NodeType == LE)
		{
			if( (lhs == INT_VAL || lhs== DOUBLE_VAL) && (rhs == INT_VAL || rhs == DOUBLE_VAL) )
				return BOOL_VAL;

			if( lhs == rhs && lhs == BOOL_VAL )
				return BOOL_VAL;

			if( lhs == rhs && lhs == STRING_VAL)
				return BOOL_VAL;

			fprintf(sem_errors_file, "Uncomparable operands for \"%s\" at line %d\n", buff, ((Exp*)exp)->linenum );
			return UNKNOWN;
		}

		return BOOL_VAL;
	}


	if(exp->NodeType == '+' || exp->NodeType == '-' || exp->NodeType == '*' || exp->NodeType == '/' )
	{
		int lhs = exp_semantics( ((Exp*)exp)->lhs );
		int rhs = exp_semantics( ((Exp*)exp)->rhs );

		if(lhs == UNKNOWN || rhs == UNKNOWN)
		{
			fprintf(sem_errors_file, "unknown type operands can't be applied to \'%c\' at line %d\n", exp->NodeType, ((Exp*)exp)->linenum );
			return UNKNOWN;
		}


		if( lhs == rhs && lhs == INT_VAL )
			return INT_VAL;

		if( lhs == rhs && lhs == DOUBLE_VAL)
			return DOUBLE_VAL;

		if ((lhs = INT_VAL && rhs == DOUBLE_VAL) || (rhs = INT_VAL && lhs == DOUBLE_VAL) )
			return DOUBLE_VAL;


		if( lhs == rhs && lhs == STRING_VAL && (exp->NodeType == '+' || exp->NodeType == '-') )
			return STRING_VAL;

		if( (lhs == STRING_VAL || rhs == STRING_VAL) && (exp->NodeType == '/' || exp->NodeType == '*') )
			fprintf(sem_errors_file, "string operands can't be applied to \'%c\' at line %d\n", exp->NodeType, ((Exp*)exp)->linenum );


		if( lhs == BOOL_VAL || rhs == BOOL_VAL )
			fprintf(sem_errors_file, "bool operands can't be applied to \'%c\' at line %d\n", exp->NodeType, ((Exp*)exp)->linenum );
	
		return UNKNOWN;
	}
}

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
		fprintf(sem_errors_file, "Use of undefined identifier \"%s\" at line %d\n",I->name, I->linenum);
	}
	
	if(s.con == 1)  // if it's a constant
	{
		fprintf(sem_errors_file, "Const Identifier \"%s\" can't be assigned a value at line %d\n",I->name, I->linenum);
	}
	else
		s.init_line = I->linenum;

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


	//3 -checking type with type of expression latter
	//exp semantics
	int r = exp_semantics( ((Stmnt*)stmnt)->rhs );
	printf("LHS = %d ,  RHS = %d \n",r, convert_chart_to_intt( s.type ) );
	if(r != convert_chart_to_intt( s.type ))
		fprintf(sem_errors_file,"lhs isn't of the same type as rhs for statement at line %d\n", I->linenum);	
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


	// add expression semantics latter
	int r = exp_semantics( ((Stmnt*)stmnt)->rhs );
	printf("LHS = %d ,  RHS = %d \n",r, convert_chart_to_intt( s.type ) );
	if(r != convert_chart_to_intt( s.type ))
		fprintf(sem_errors_file, "lhs isn't of the same type as rhs for statement at line %d\n", I->linenum);
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


	// checking type of expression && expression should be variable free
	
	int r = exp_semantics( ((Stmnt*)stmnt)->rhs );
	printf("LHS = %d ,  RHS = %d \n",r, convert_chart_to_intt( s.type ) );
	if(r != convert_chart_to_intt( s.type ))
		fprintf(sem_errors_file, "lhs isn't of the same type as rhs for statement at line %d\n", I->linenum);	
}

void id_semantics(TreeNode * id)
{
	Id* I = (Id*)id;
	Symbol s = get_symbol(I->name);

	//check semantics
	if(s.def_line == not_defined)
	{
		fprintf(sem_errors_file, "Use of undefined identifier \"%s\" at line %d\n",I->name, I->linenum);
	}
	else if(s.init_line == not_initialized)
	{			
		fprintf(sem_errors_file, "Use of uninitialzed identifier \"%s\" at line %d\n",I->name, I->linenum);
	}

	//add to symbol table
	if(strcmp(s.name, "") == 0)
	{
		strcpy(s.name, I->name);
		add_symbol(s);
	}
}

void flow_semantics(TreeNode * flow)
{
	int r = exp_semantics(((Flow *)flow)->cond);

	if(r != BOOL_VAL)
	{
		if(flow->NodeType == IF)
			fprintf(sem_errors_file, "If condition doesn't have bool type at line %d \n",  ((Exp*)(((Flow*)flow)->cond))->linenum); 
		else if(flow->NodeType == WHILE)
			fprintf(sem_errors_file, "while condition doesn't have bool type at line %d \n",  ((Exp*)(((Flow*)flow)->cond))->linenum); 
		else if(flow->NodeType == REPEAT)
			fprintf(sem_errors_file, "repeat condition doesn't have bool type at line %d \n",  ((Exp*)(((Flow*)flow)->cond))->linenum); 
	}
}

void for_semantics(TreeNode * for_obj)
{
	// check for decl stmnt (previously checked)

	//checking semantics for stop conditoin
	int r = exp_semantics( ((For*)for_obj)->cond );
	if(r != BOOL_VAL)
		fprintf(sem_errors_file, "for loop stop condition found at line: %d isn't bool\n", ((Exp*)(((For*)for_obj)->cond))->linenum );


	//checking semantics for assi stmnt
	Assi_list* al = (Assi_list*)(((For*)for_obj)->assi_list);

	while(al != NULL)
	{
		assi_stmnt_semantics( (TreeNode*)(al->astmnt) );
		al = (Assi_list*)al->alist;
	}
}

void decl_list_semantics(TreeNode * assi_list)
{
	Assi_list* al = (Assi_list*)assi_list; 
	while( al != NULL)
	{
		printf("howa da");
		decl_assi_stmnt_semantics( (TreeNode*)(al->astmnt) );
		al = (Assi_list*)al->alist;
	}
}

void switch_semantics(TreeNode * switch_obj)
{
	Exp* s_exp =  (Exp*)(((Switch*)switch_obj)->exp);


	// switch expression must be a valid one
	int s_exp_type = exp_semantics((TreeNode*)s_exp);
	if(s_exp_type == UNKNOWN)
		fprintf(sem_errors_file, "Switch expression unknown type at line %d \n", s_exp->linenum);


	Swbody* s_body = (Swbody*)(((Switch*)switch_obj)->body);

	while(s_body != NULL)
	{
		Exp* e = (Exp*)(((Case*)(s_body->case_block))->case_exp);
		if (e != NULL)
		{
			int case_exp_type = exp_semantics((TreeNode*)e);

			if(case_exp_type != s_exp_type)
				fprintf(sem_errors_file, "case exp type at line %d is not the same as switch exp at line %d", e->linenum, s_exp->linenum ); 
		}
		s_body = (Swbody*)(s_body->sbody);
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


