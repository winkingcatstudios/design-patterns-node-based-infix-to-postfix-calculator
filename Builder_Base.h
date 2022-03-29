#pragma once
#include "Add_Node.h"
#include "Divide_Node.h"
#include "Mod_Node.h"
#include "Multiply_Node.h"
#include "Num_Node.h"
#include "Subtract_Node.h"
#include "Stack.h"

#ifndef _BUILDER_BASE_H
#define _BUILDER_BASE_H

class Builder_Base 
{
public:

	//	Destructor
	virtual ~Builder_Base(void) {};

	//	Builds add
	virtual void build_add_operator(void) = 0;

	//	Builds divide
	virtual void build_divide_operator(void) = 0;

	//	Builds mod
	virtual void build_mod_operator(void) = 0;

	//	Builds multiply
	virtual void build_multiply_operator(void) = 0;

	//	Builds numbers
	virtual void build_number(int n) = 0;

	//	Builds subtract
	virtual void build_subtract_operator(void) = 0;

	//	Builds node based on token from infix
	virtual Expr_Node* build_node(void) = 0;

	//	Get the expression tree
	virtual Expr_Node* get_expression(void) = 0;
};

#endif	// !defined _BUILDER_BASE_H
