#include "Mod_Node.h"

//	Constructor
Mod_Node::Mod_Node(void)
{}

//	Destructor
Mod_Node::~Mod_Node(void)
{}

//	Precedence
int Mod_Node::precedence(void)
{
	return 5;
}

//	Accepts visitor
void Mod_Node::accept(Visitor_Base& v)
{
	v.visit_mod_node(*this);
}