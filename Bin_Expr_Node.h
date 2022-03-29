#pragma once

// Forward declaration
class Visitor_Base;

#ifndef _BIN_EXPR_NODE_H
#define _BIN_EXPR_NODE_H

#include "Expr_Node.h"

class Bin_Expr_Node : public Expr_Node
{
public:

	//	Constructor
	Bin_Expr_Node(void);

	//	Destructor
	virtual ~Bin_Expr_Node(void);

	// Get left node
	Expr_Node* left_getter(void);

	// Get right node
	Expr_Node* right_getter(void);

	//	Set left node
	void left_setter(Expr_Node*);

	//	Set right note
	void right_setter(Expr_Node*);

	//	Precedence
	virtual int precedence(void);

	//	Accepts visitor
	virtual void accept(Visitor_Base& v);

protected:
	// Left child node in tree
	Expr_Node* left_;

	// Right child node in tree
	Expr_Node* right_;

	//	Virtual value getter for num, must include for polymorphic behavior
	virtual int getValue(void);
};
#endif	// !defined _BIN_EXPR_NODE_H