
TreeNode * newNODE(int type)
{
	TreeNode * T = malloc(sizeof(TreeNode));
	T->NodeType = type;
	return T;
}


TreeNode * newINT(int value)
{
	Int * I = malloc(sizeof(Int));
	I->NodeType = INT_VAL;
	I->i = value;
	return (TreeNode *) I;
}


TreeNode * newDOUBLE(double value)
{
	Double * D = malloc(sizeof(Double));
	D->NodeType = DOUBLE_VAL;
	D->d = value;
	return (TreeNode *) D;
}


TreeNode * newBOOL(int value)
{
	Bool * B = malloc(sizeof(Bool));
	B->NodeType = BOOL_VAL;
	B->b = value;
	return (TreeNode *) B;
}

TreeNode * newSTRING(char* value)
{
	String * S = malloc(sizeof(String));
	S->NodeType = STRING_VAL;
	S->s = value;
	return (TreeNode *) S;
}

TreeNode * newCHAR(char value)
{
	Char * C = malloc(sizeof(Char));
	C->NodeType = CHAR_VAL;
	C->c = value;
	return (TreeNode *) C;
}


TreeNode * newID(char * name)
{
	Id * I = malloc(sizeof(Id));
	I->NodeType = ID;
	I->name = name;
	return (TreeNode *) I;
}


TreeNode * newEXP(int type, TreeNode * left, TreeNode * right)
{
	Exp * E = malloc(sizeof(Exp));
	E->NodeType = type;
	E->rhs = right;
	E->lhs = left;
	return (TreeNode *) E;
}


TreeNode * newSTMNT1(char * id, TreeNode * rhs)
{
	
	Id * I = malloc(sizeof(Id));
	I->name = id;
	I->NodeType = ID;

	Stmnt1 * S = malloc(sizeof(Stmnt1));
	S->NodeType = STMNT1;
	S->Id = (TreeNode *) I;
	S->rhs = rhs;

	return (TreeNode *) S;
}


TreeNode * newFLOW(int type, TreeNode* cond, TreeNode* if_brnch, TreeNode* el_brnch)
{
	Flow * F = malloc(sizeof(Flow));
	F->NodeType = type;
	F->cond = cond;
	F->if_brnch = if_brnch;
	F->els_brnch = el_brnch;

	return (TreeNode *) F;
}


TreeNode * newFOR(TreeNode * decl_list, TreeNode * cond, TreeNode * assi_list, TreeNode * body)
{
	For * F = malloc(sizeof(For));
	F->NodeType = FOR;
	F->decl_list = decl_list;
	F->cond = cond;
	F->assi_list = assi_list;
	F->body = body;

	return (TreeNode *) F;
}


TreeNode * newSWITCH(TreeNode * exp, TreeNode * sw_body)
{
	Switch * S = malloc(sizeof(Switch));
	S->NodeType = SWITCH;
	S->exp = exp;
	S->body = sw_body;

	return (TreeNode *) S;
}


TreeNode * newCASE(int type, TreeNode * c_exp, TreeNode * c_list)
{
	Case * C = malloc(sizeof(Case));
	C->NodeType = type;
	C->case_exp = c_exp;
	C->case_list = c_list;

	return (TreeNode *) C;
}


TreeNode * newSBODY( TreeNode * case_block, TreeNode * sw_body)
{
	Swbody * S = malloc(sizeof(Swbody));
	S->NodeType = SWBODY;
	S->case_block = case_block;
	S->sbody = sw_body;

	return (TreeNode *) S;
}


TreeNode * newALIST(TreeNode * astmnt, TreeNode * alist)
{
	Assi_list * A = malloc(sizeof(Assi_list));
	A->NodeType = ASSI_LIST;
	A->astmnt = astmnt;   
	A->alist = alist;

	return (TreeNode *) A;
}


TreeNode * newDLIST(TreeNode * alist)
{
	Decl_list * D = malloc(sizeof(Decl_list));
	D->NodeType = DECL_LIST;
	D->alist = alist;

	return (TreeNode *) D;
}


TreeNode * newLIST(TreeNode * st, TreeNode * l)
{
	List * L = malloc(sizeof(List));
	L->NodeType = LIST;
	L->statement = st;
	L->list = l;

	return (TreeNode *) L;
}