#ifndef _VISITOR_BASE_H
#define _VISITOR_BASE_H

#include "Add_Node.h"
#include "Divide_Node.h"
#include "Mod_Node.h"
#include "Multiply_Node.h"
#include "Num_Node.h"
#include "Subtract_Node.h"

class Visitor_Base
{
public:

	//	Destructor
	virtual ~Visitor_Base(void) {};

	//	//	Visit add node
	virtual void visit_add_node(Expr_Node& node) = 0;

	//	Visit divide node
	virtual void visit_divide_node(Expr_Node& node) = 0;

	//	Visit mod node
	virtual void visit_mod_node(Expr_Node& node) = 0;

	//	Visit multiply node
	virtual void visit_multiply_node(Expr_Node& node) = 0;

	//	Visit number node
	virtual void visit_number_node(Expr_Node& node) = 0;

	//	Visit subtract node
	virtual void visit_subtract_node(Expr_Node& node) = 0;

	//	Get left value
	virtual void left_value(Expr_Node& node) = 0;

	//	Get right value
	virtual void right_value(Expr_Node& node) = 0;
};

#endif	// !defined _VISITOR_BASE_H
