#include "Add_Node.h"

//	Constructor
Add_Node::Add_Node(void)
{}

//	Destructor
Add_Node::~Add_Node(void)
{}

//	Precedence
int Add_Node::precedence(void)
{
	return 1;
}

//	Accepts visitor
void Add_Node::accept(Visitor_Base& v)
{
	v.visit_add_node(*this);
}