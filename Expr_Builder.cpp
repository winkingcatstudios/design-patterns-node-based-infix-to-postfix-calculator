#include "Expr_Builder.h"
#include <sstream>
#include <iostream>

//	Constructor
Expr_Builder::Expr_Builder(void)
    :root_(nullptr)
{}

//	Constructor with initialization
Expr_Builder::Expr_Builder(Array<std::string> infix)
    :index_(0),
    root_(nullptr),
    infix_(infix),
    exprNodes_(Array<Expr_Node*>(infix.size()))
{}

//	Destructor 
Expr_Builder::~Expr_Builder(void)
{}

//	Builds add
void Expr_Builder::build_add_operator(void)
{
    exprNodes_[index_] = new Add_Node();
}

//	Builds divide
void Expr_Builder::build_divide_operator(void)
{
    exprNodes_[index_] = new Divide_Node();
}

//	Builds mod
void Expr_Builder::build_mod_operator(void)
{
    exprNodes_[index_] = new Mod_Node();
}

//	Builds multiply
void Expr_Builder::build_multiply_operator(void)
{
    exprNodes_[index_] = new Multiply_Node();
}

//	Builds numbers
void Expr_Builder::build_number(int n)
{
    exprNodes_[index_] = new Num_Node(n);
}

//	Builds subtract
void Expr_Builder::build_subtract_operator(void)
{
    exprNodes_[index_] = new Subtract_Node();
}

//	Builds node based on token from infix
Expr_Node* Expr_Builder::build_node(void)
{
    //creates node version of each token and adds to node array
    while (this->index_ < this->infix_.size())
    {
        std::string token = this->infix_[index_];
        if (token == "+")
            this->build_add_operator();
        else if (token == "-")
            this->build_subtract_operator();
        else if (token == "*")
            this->build_multiply_operator();
        else if (token == "/")
            this->build_divide_operator();
        else if (token == "%")
            this->build_mod_operator();
        else if (isdigit(token[0]) || token[0] == '-')
        {
            if (token.find_first_not_of("0123456789", 1) == std::string::npos)
            {
                std::stringstream ss(token);
                int value;
                ss >> value;
                this->build_number(value);
            }
            else
                throw std::logic_error("Invalid expression");
        }
        else
            throw std::logic_error("Invalid expression");

        this->index_++;
    }
    //  Builds tree from nodes
    this->tree_builder();
}

//	Builds tree from nodes
void Expr_Builder::tree_builder(void)
{
        //  Build tree from newly build nodes
        this->index_ = 0;
        for (int i = this->index_; i < this->exprNodes_.size(); i++)
        {
            //  Start with high (3-5 precendence) multiply, divide, mod
            if (this->exprNodes_[this->index_]->precedence() >= 3 
                || this->exprNodes_[this->index_]->precedence() == 4
                || this->exprNodes_[this->index_]->precedence() == 5)
            {
                this->exprNodes_[this->index_]->left_setter(this->exprNodes_[this->index_ - 1]);
                this->exprNodes_[this->index_]->right_setter(this->exprNodes_[this->index_ + 1]);
    
                this->exprNodes_[this->index_ - 1] = this->exprNodes_[this->index_];
                for (int i = this->index_; i < this->exprNodes_.size() - 2; i++)
                    this->exprNodes_[i] = this->exprNodes_[i + 2];
    
                this->exprNodes_.resize(this->exprNodes_.size() - 2);
            }
            else
                this->index_++;
        }
     
        //  Then low precedence (1 or 2) add, subtract
        this->index_ = 0;
        for (int i = this->index_; i < this->exprNodes_.size(); i++)
        {
            if (this->exprNodes_[this->index_]->precedence() == 1
                || this->exprNodes_[this->index_]->precedence() == 2)
            {
                this->exprNodes_[this->index_]->left_setter(this->exprNodes_[this->index_ - 1]);
                this->exprNodes_[this->index_]->right_setter(this->exprNodes_[this->index_ + 1]);
    
                this->exprNodes_[this->index_ - 1] = this->exprNodes_[this->index_];
                for (int i = this->index_; i < this->exprNodes_.size() - 2; i++)
                    this->exprNodes_[i] = this->exprNodes_[i + 2];
    
                this->exprNodes_.resize(this->exprNodes_.size() - 2);
            }
            else
                this->index_++;
        }
}

//	Get the expression tree
Expr_Node* Expr_Builder::get_expression(void)
{
    return this->exprNodes_[0];
}