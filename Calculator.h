#pragma once
#ifndef _CALCULATOR_H
#define _CALCULATOR_H

#include "Expr_Node.h"
#include "Expr_Builder.h"
#include "Expr_Node_Visitor.h"
#include "Array.h"
#include "Stack.h"
#include "Queue.h"
#include <string>
#include <iostream>
#include <sstream>
#include <map>

// Calculator class
class Calculator
{
public:

	//	Constructor
	Calculator(void);

	//	Destructor
	~Calculator(void);

	//	Wrapper facade interface
	void calc(std::string expr);

	//	Evalutates infix
	int evaluate(Array<std::string> infix);

	//	Parser
	Array<std::string> parse(std::string expr);

	//	Number check
	bool isNum(std::string str);

};
#endif	// !defined _CALCULATOR_H