#pragma once
#include "Visitor_Base.h"
#include <stdexcept>

#ifndef _EXPR_NODE_VISITOR_H
#define _EXPR_NODE_VISITOR_H

//	Base class for commands
class Expr_Node_Visitor : public Visitor_Base
{
public:

	//	Constructor
	Expr_Node_Visitor(void);

	//	Destructor
	~Expr_Node_Visitor(void);

	//	Visit add node
	void visit_add_node(Expr_Node& node);

	//	Visit divide node
	void visit_divide_node(Expr_Node& node);

	//	Visit mod node
	void visit_mod_node(Expr_Node& node);

	//	Visit multiply node
	void visit_multiply_node(Expr_Node& node);

	//	Visit number node
	void visit_number_node(Expr_Node& node);

	//	Visit subtract node
	void visit_subtract_node(Expr_Node& node);

	//	Get left value
	void left_value(Expr_Node& node);

	//	Get right value
	void right_value(Expr_Node& node);

	//	Get current value
	int current_value(void);

private:

	//	Value for current_value
	int value_;
};
#endif	// !defined _EXPR_NODE_VISITOR_H