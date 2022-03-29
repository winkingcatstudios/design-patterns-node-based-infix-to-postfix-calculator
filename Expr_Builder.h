#pragma once
#include "Builder_Base.h"
#include <string>

#ifndef _EXPR_BUILDER_H
#define _EXPR_BUILDER_H

//	Expression Builder Class
class Expr_Builder : public Builder_Base
{
public:

	//	Constructor
	Expr_Builder(void);

	//	Constructor with initialization
	Expr_Builder(Array<std::string> infix);

	//	Destructor 
	virtual ~Expr_Builder(void);

	//	Builds add
	virtual void build_add_operator(void);

	//	Builds divide
	virtual void build_divide_operator(void);

	//	Builds mod
	virtual void build_mod_operator(void);

	//	Builds multiply
	virtual void build_multiply_operator(void);

	//	Builds numbers
	virtual void build_number(int n);

	//	Builds subtract
	virtual void build_subtract_operator(void);

	//	Builds node based on token from infix
	virtual Expr_Node* build_node(void);

	//	Get the expression tree
	Expr_Node* get_expression(void);

	//	Builds tree from nodes
	void tree_builder(void);

private:

	//	Tree index
	int index_;

	//	Tree root
	Expr_Node* root_;

	//	Infix string
	Array<std::string> infix_;

	//	Infex nodes
	Array<Expr_Node*> exprNodes_;
};
#endif	// !defined _EXPR_BUILDER_H