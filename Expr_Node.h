#pragma once

// Forward declaration
class Visitor_Base;

#ifndef _EXPR_NODE_H
#define _EXPR_NODE_H

//	Base class for commands
class Expr_Node
{
public:

	//	Destructor
	virtual ~Expr_Node(void) {};

	// Get left node
	virtual Expr_Node* left_getter(void) = 0;

	// Get right node
	virtual Expr_Node* right_getter(void) = 0;

	//	Set left node
	virtual void left_setter(Expr_Node*) = 0;

	//	Set right note
	virtual void right_setter(Expr_Node*) = 0;

	//	Precedence
	virtual int precedence(void) = 0;

	//	Virtual value getter for num, must include for polymorphic behavior
	virtual int getValue(void) = 0;

	//	Accepts visitor
	virtual void accept(Visitor_Base& v) = 0;

};
#endif	// !defined _EXPR_NODE_H