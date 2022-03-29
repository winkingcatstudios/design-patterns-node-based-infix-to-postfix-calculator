#include "Divide_Node.h"

//	Constructor
Divide_Node::Divide_Node(void)
{}

//	Destructor
Divide_Node::~Divide_Node(void)
{}

//	Precedence
int Divide_Node::precedence(void)
{
	return 4;
}

//	Accepts visitor
void Divide_Node::accept(Visitor_Base& v)
{
	v.visit_divide_node(*this);
}