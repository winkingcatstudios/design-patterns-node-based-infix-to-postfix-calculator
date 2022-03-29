#include "Num_Node.h"

//	Constructor
Num_Node::Num_Node(int n)
	:val_(n)
{}

//	Destructor
Num_Node::~Num_Node(void)
{}

//	Precedence (doesn't really have a mathematically precedene, this is more of an identifier for build)
int Num_Node::precedence(void)
{
	return 0;
}

//	Accepts visitor
void Num_Node::accept(Visitor_Base& v)
{
	v.visit_number_node(*this);
}

//	Value getter
int Num_Node::getValue(void)
{
	return this->val_;
}

// Expr_Node functions must be declared from pure virtual
Expr_Node* Num_Node::left_getter(void) {}
Expr_Node* Num_Node::right_getter(void) {}
void Num_Node::left_setter(Expr_Node* node) {}
void Num_Node::right_setter(Expr_Node* node) {}