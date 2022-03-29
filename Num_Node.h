#include "Visitor_Base.h"

#ifndef _NUM_NODE_H
#define _NUM_NODE_H

#include "Expr_Node.h"

class Num_Node : public Expr_Node
{
public:

	//	Constructor
	Num_Node(int n);

	//	Destructor
	~Num_Node(void);

	//	Precedence
	virtual int precedence(void);

	//	Accepts visitor
	virtual void accept(Visitor_Base& v);

	//	Value getter
	int getValue(void);

private:
	//Number stored in node
	int val_;

	// Expr_Node functions must be declared from pure virtual
	Expr_Node* left_getter(void);
	Expr_Node* right_getter(void);
	void left_setter(Expr_Node*);
	void right_setter(Expr_Node*);
};
#endif	// !defined _NUM_NODE_H

