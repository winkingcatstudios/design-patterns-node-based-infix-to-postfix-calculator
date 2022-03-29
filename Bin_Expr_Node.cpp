#include "Bin_Expr_Node.h"

//	Constructor
Bin_Expr_Node::Bin_Expr_Node(void)
	:left_(nullptr),
	right_(nullptr)
{}

//	Destructor
Bin_Expr_Node::~Bin_Expr_Node(void)
{
	delete this->left_;
	delete this->right_;
}

// Get left node
Expr_Node* Bin_Expr_Node::left_getter(void)
{
	return this->left_;
}

// Get right node
Expr_Node* Bin_Expr_Node::right_getter(void)
{
	return this->right_;
}

//	Set left node
void Bin_Expr_Node::left_setter(Expr_Node* node)
{
	this->left_ = node;
}

//	Set right note
void Bin_Expr_Node::right_setter(Expr_Node* node)
{
	this->right_ = node;
}

//	Precendence
int Bin_Expr_Node::precedence(void)
{}

// Virtual value getter for num, must include for polymorphic behavior
int Bin_Expr_Node::getValue(void)
{}

//	Accepts visitor
void Bin_Expr_Node::accept(Visitor_Base& v)
{}
