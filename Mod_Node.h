#pragma once
#include "Bin_Expr_Node.h"
#include "Visitor_Base.h"

#ifndef _MOD_NODE_H
#define _MOD_NODE_H

class Mod_Node : public Bin_Expr_Node
{
public:

	//	Constructor
	Mod_Node(void);

	//	Destructor
	virtual ~Mod_Node(void);

	//	Precedence
	virtual int precedence(void);

	//	Accepts visitor
	virtual void accept(Visitor_Base& v);
};
#endif	// !defined _MOD_NODE_H
