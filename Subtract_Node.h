#include "Visitor_Base.h"

#ifndef _SUBTRACT_NODE_H
#define _SUBTRACT_NODE_H

#include "Bin_Expr_Node.h"

class Subtract_Node : public Bin_Expr_Node
{
public:

	//	Constructor
	Subtract_Node(void);

	//	Destructor
	virtual ~Subtract_Node(void);

	//	Precedence
	virtual int precedence(void);

	//	Accepts visitor
	virtual void accept(Visitor_Base& v);
};
#endif	// !defined _SUBTRACT_NODE_H
