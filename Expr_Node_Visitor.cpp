#include "Expr_Node_Visitor.h"

//  Constructor
Expr_Node_Visitor::Expr_Node_Visitor(void)
    :value_(0)
{}

//  Destructor
Expr_Node_Visitor::~Expr_Node_Visitor(void)
{}

//  Add child nodes
void Expr_Node_Visitor::visit_add_node(Expr_Node& node)
{
    int left, right;
    
    // COMMENT You are not using the visitor pattern correctly here. You should
    // be calling the accept method on each node (i.e., this->left_getter()->accept (*this);
    // This will remove the need for knowing the node types the double dispatch will cause
    // the flow to go to the most abstract node type and then call back up into the visitor
    // at the visit method for the node. Your left_value() and right_value() methods are
    // doing what the visitor would do in O(n) time.
    // RESPONSE refactored visitor to no longer need to know the concrete node types.
    // visitor now takes in abstract expr nodes to visit
    this->left_value(node);
    left = this->value_;

    // COMMENT You are not using the visitor pattern correctly here. You should
    // be calling the accept method on each node (i.e., this->left_getter()->accept (*this);
    // This will remove the need for knowing the node types the double dispatch will cause
    // the flow to go to the most abstract node type and then call back up into the visitor
    // at the visit method for the node. Your left_value() and right_value() methods are
    // doing what the visitor would do in O(n) time.
    // RESPONSE refactored visitor to no longer need to know the concrete node types.
    // visitor now takes in abstract expr nodes to visit
    this->right_value(node);
    right = this->value_;

    this->value_ = left + right;
}

//  Divide child nodes
void Expr_Node_Visitor::visit_divide_node(Expr_Node& node)
{
    int left, right;

    // COMMENT You are not using the visitor pattern correctly here. You should
    // be calling the accept method on each node (i.e., this->left_getter()->accept (*this);
    // This will remove the need for knowing the node types the double dispatch will cause
    // the flow to go to the most abstract node type and then call back up into the visitor
    // at the visit method for the node. Your left_value() and right_value() methods are
    // doing what the visitor would do in O(n) time.
    // RESPONSE refactored visitor to no longer need to know the concrete node types.
    // visitor now takes in abstract expr nodes to visit
    this->left_value(node);
    left = this->value_;

    // COMMENT You are not using the visitor pattern correctly here. You should
    // be calling the accept method on each node (i.e., this->left_getter()->accept (*this);
    // This will remove the need for knowing the node types the double dispatch will cause
    // the flow to go to the most abstract node type and then call back up into the visitor
    // at the visit method for the node. Your left_value() and right_value() methods are
    // doing what the visitor would do in O(n) time.
    // RESPONSE refactored visitor to no longer need to know the concrete node types.
    // visitor now takes in abstract expr nodes to visit
    this->right_value(node);
    right = this->value_;

    if (right == 0)
        throw std::logic_error("Invalid expression");
    else
        this->value_ = left / right;
}

//  Mod child nodes
void Expr_Node_Visitor::visit_mod_node(Expr_Node& node)
{
    int left, right;

    // COMMENT You are not using the visitor pattern correctly here. You should
    // be calling the accept method on each node (i.e., this->left_getter()->accept (*this);
    // This will remove the need for knowing the node types the double dispatch will cause
    // the flow to go to the most abstract node type and then call back up into the visitor
    // at the visit method for the node. Your left_value() and right_value() methods are
    // doing what the visitor would do in O(n) time.
    // RESPONSE refactored visitor to no longer need to know the concrete node types.
    // visitor now takes in abstract expr nodes to visit
    this->left_value(node);
    left = this->value_;

    // COMMENT You are not using the visitor pattern correctly here. You should
    // be calling the accept method on each node (i.e., this->left_getter()->accept (*this);
    // This will remove the need for knowing the node types the double dispatch will cause
    // the flow to go to the most abstract node type and then call back up into the visitor
    // at the visit method for the node. Your left_value() and right_value() methods are
    // doing what the visitor would do in O(n) time.
    // RESPONSE refactored visitor to no longer need to know the concrete node types.
    // visitor now takes in abstract expr nodes to visit
    this->right_value(node);
    right = this->value_;

    this->value_ = left % right;
}

//  Multiply child nodes
void Expr_Node_Visitor::visit_multiply_node(Expr_Node& node)
{
    int left, right;

    // COMMENT You are not using the visitor pattern correctly here. You should
    // be calling the accept method on each node (i.e., this->left_getter()->accept (*this);
    // This will remove the need for knowing the node types the double dispatch will cause
    // the flow to go to the most abstract node type and then call back up into the visitor
    // at the visit method for the node. Your left_value() and right_value() methods are
    // doing what the visitor would do in O(n) time.
    // RESPONSE refactored visitor to no longer need to know the concrete node types.
    // visitor now takes in abstract expr nodes to visit
    this->left_value(node);
    left = this->value_;
    
    // COMMENT You are not using the visitor pattern correctly here. You should
    // be calling the accept method on each node (i.e., this->left_getter()->accept (*this);
    // This will remove the need for knowing the node types the double dispatch will cause
    // the flow to go to the most abstract node type and then call back up into the visitor
    // at the visit method for the node. Your left_value() and right_value() methods are
    // doing what the visitor would do in O(n) time.
    // RESPONSE refactored visitor to no longer need to know the concrete node types.
    // visitor now takes in abstract expr nodes to visit
    this->right_value(node);
    right = this->value_;
    
    this->value_ = left * right;
}

//  Get number node
void Expr_Node_Visitor::visit_number_node(Expr_Node& node)
{
    this->value_ = node.getValue();
}

//  Subtract chold nodes
void Expr_Node_Visitor::visit_subtract_node(Expr_Node& node)
{
    int left, right;

    // COMMENT You are not using the visitor pattern correctly here. You should
    // be calling the accept method on each node (i.e., this->left_getter()->accept (*this);
    // This will remove the need for knowing the node types the double dispatch will cause
    // the flow to go to the most abstract node type and then call back up into the visitor
    // at the visit method for the node. Your left_value() and right_value() methods are
    // doing what the visitor would do in O(n) time.
    // RESPONSE refactored visitor to no longer need to know the concrete node types.
    // visitor now takes in abstract expr nodes to visit
    this->left_value(node);
    left = this->value_;

    // COMMENT You are not using the visitor pattern correctly here. You should
    // be calling the accept method on each node (i.e., this->left_getter()->accept (*this);
    // This will remove the need for knowing the node types the double dispatch will cause
    // the flow to go to the most abstract node type and then call back up into the visitor
    // at the visit method for the node. Your left_value() and right_value() methods are
    // doing what the visitor would do in O(n) time.
    // RESPONSE refactored visitor to no longer need to know the concrete node types.
    // visitor now takes in abstract expr nodes to visit
    this->right_value(node);
    right = this->value_;

    this->value_ = left - right;
}

//  Get left child
void Expr_Node_Visitor::left_value(Expr_Node& node)
{
    int nodeType = node.left_getter()->precedence();
    if (nodeType == 0)
        this->visit_number_node(*node.left_getter());
    else if (nodeType == 1)
        this->visit_add_node(*node.left_getter());
    else if (nodeType == 2)
        this->visit_subtract_node(*node.left_getter());
    else if (nodeType == 3)
        this->visit_multiply_node(*node.left_getter());
    else if (nodeType == 4)
        this->visit_divide_node(*node.left_getter());
    else if (nodeType == 5)
        this->visit_mod_node(*node.left_getter());
    else
        throw std::logic_error("Invalid expression");
}

//  Get right child
void Expr_Node_Visitor::right_value(Expr_Node& node)
{
    int nodeType = node.right_getter()->precedence();
    if (nodeType == 0)
        this->visit_number_node(*node.right_getter());
    else if (nodeType == 1)
        this->visit_add_node(*node.right_getter());
    else if (nodeType == 2)
        this->visit_subtract_node(*node.right_getter());
    else if (nodeType == 3)
        this->visit_multiply_node(*node.right_getter());
    else if (nodeType == 4)
        this->visit_divide_node(*node.right_getter());
    else if (nodeType == 5)
        this->visit_mod_node(*node.right_getter());
    else
        throw std::logic_error("Invalid expression");
}

//  Get current value
int Expr_Node_Visitor::current_value(void)
{
    return this->value_;
}
