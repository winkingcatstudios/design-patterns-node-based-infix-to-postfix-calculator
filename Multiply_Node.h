#pragma once
#include "Bin_Expr_Node.h"
#include "Visitor_Base.h"

#ifndef _MULTIPLY_NODE_H
#define _MULTIPLY_NODE_H

class Multiply_Node : public Bin_Expr_Node
{
public:

	//	Constructor
	Multiply_Node(void);

	//	Destructor
	virtual ~Multiply_Node(void);

	//	Precedence
	virtual int precedence(void);

	//	Accepts visitor
	virtual void accept(Visitor_Base& v);
};
#endif	// !defined _MULTIPLY_NODE_H
