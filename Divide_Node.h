#pragma once
#include "Bin_Expr_Node.h"
#include "Visitor_Base.h"

#ifndef _DIVIDE_NODE_H
#define _DIVIDE_NODE_H

class Divide_Node : public Bin_Expr_Node
{
public:

	//	Constructor
	Divide_Node(void);

	//	Destructor
	virtual ~Divide_Node(void);

	//	Precedence
	virtual int precedence(void);

	//	Accepts visitor
	virtual void accept(Visitor_Base& v);
};
#endif	// !defined _DIVIDE_NODE_H
