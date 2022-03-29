#include "Multiply_Node.h"

//	Constructor
Multiply_Node::Multiply_Node(void)
{}

//	Destructor
Multiply_Node::~Multiply_Node(void)
{}

//	Precedence
int Multiply_Node::precedence(void)
{
	return 3;
}

//	Accepts visitor
void Multiply_Node::accept(Visitor_Base& v)
{
	v.visit_multiply_node(*this);
}
