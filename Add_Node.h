#pragma once
#include "Bin_Expr_Node.h"
#include "Visitor_Base.h"

#ifndef _ADD_NODE_H
#define _ADD_NODE_H

class Add_Node : public Bin_Expr_Node
{
public:

	//	Constructor
	Add_Node(void);

	//	Destructor
	virtual ~Add_Node(void);

	//	Precedence
	virtual int precedence(void);

	//	Accepts visitor
	virtual void accept(Visitor_Base& v);
};
#endif	// !defined _ADD_NODE_H_