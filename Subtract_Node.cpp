#include "Subtract_Node.h"

//	Constructor
Subtract_Node::Subtract_Node(void)
{}

//	Destructor
Subtract_Node::~Subtract_Node(void)
{}

//	Precedence
int Subtract_Node::precedence(void)
{
	return 2;
}

//	Accepts visitor
void Subtract_Node::accept(Visitor_Base& v)
{
	v.visit_subtract_node(*this);
}