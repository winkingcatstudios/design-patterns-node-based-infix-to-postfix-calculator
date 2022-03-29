#include "Calculator.h"

//	Constructor
Calculator::Calculator(void)
{}

//	Destructor
Calculator::~Calculator(void)
{}

//  Wrapper facade interface to calculator. Combibed parser and evaluator and prints output
void Calculator::calc(std::string expression)
{
    // Parse input and display results
    Array<std::string> infix;
    infix = parse(expression);
    std::cout << "Result: " << evaluate(infix) << std::endl;

}

//  Turn input expression into infix tokens
Array<std::string> Calculator::parse(std::string expression)
{
    //  Stringstream variables
    Queue<std::string> tokenStream;
    std::stringstream ss(expression);
    std::string token;

    //  A single space deliniates the next token from input
    //  Note: this is not best practice, but works with this project's guidelines
    while (getline(ss, token, ' '))
        tokenStream.enqueue(token);

    //  Create infix array from parsed tokens
    Array<std::string> infix(tokenStream.size());
    for (int i = 0; i < infix.size(); i++)
    {
        infix[i] = tokenStream.end();
        tokenStream.dequeue();
    }
    return infix;
}

//  Handle parenthesese, build expr, build tree, visit notes to get results
int Calculator::evaluate(Array<std::string> infix)
{
    Stack<std::string> prefix;
    int parenthesesPos = 0;
    while (parenthesesPos < infix.size())
    {
        if (infix[parenthesesPos] == "(")
        {
            // Track parentheses for pairs and nesting, and loop to find all parentheses
            int parenthesesCount = 0;
            int nextParentheses = parenthesesPos + 1;
            bool hasParentheses = true;

            while (hasParentheses)
            {
                if (infix[nextParentheses] == "(")
                {
                    parenthesesCount++;
                    nextParentheses++;
                }
                else if (infix[nextParentheses] == ")")
                {
                    if (parenthesesCount == 0)
                        hasParentheses = false;
                    else
                    {
                        parenthesesCount--;
                        nextParentheses++;
                    }
                }
                else
                    nextParentheses++;

                // No closing parentheses found for opening parentheses
                if (nextParentheses >= infix.size())
                    throw std::logic_error("Invalid expression");
            }

            //  Pull parentheses expressionss into their own array to evaluate seperately (first)
            Array<std::string> parenthesesExpression(nextParentheses - parenthesesPos - 1);
            int parenthesesIndex = 0;
            for (int i = parenthesesPos + 1; i < nextParentheses; i++)
            {
                parenthesesExpression[parenthesesIndex] = infix[i];
                parenthesesIndex++;
            }

            //  Evaluate parentheses first due to highest precedence since they are not a command type with a precendence method
            std::stringstream ss;
            ss << evaluate(parenthesesExpression);
            infix[parenthesesPos] = ss.str();

            //  Shift and resize infix once parentheses are evaluated out
            int shift = nextParentheses - parenthesesPos;
            int infixParenthesesindex = nextParentheses + 1;
            while (infixParenthesesindex < infix.size())
            {
                infix[infixParenthesesindex - shift] = infix[infixParenthesesindex];
                infixParenthesesindex++;
            }
            infix.resize(infix.size() - shift);
        }
        parenthesesPos++;
    }

    //  Instatiate builder, build nodes, build tree
    Expr_Builder exprBuilder(infix);
    exprBuilder.build_node();
    Expr_Node* exprTree = exprBuilder.get_expression();

    //  Instatiate visitor and traverse tree
    Expr_Node_Visitor exprVisitor;
    exprTree->accept(exprVisitor);
    int result = exprVisitor.current_value();

    //  Clean up and return
    delete exprTree;
    return result;
}

//  Check if a token is a number. 
//  All input other thatn these, operators, and "QUIT" will be treated as garbage input
bool Calculator::isNum(std::string str)
{
    // Check if the token starts with a number or a negative sign
    if (isdigit(str[0]) || str[0] == '-')
    {
        // Searches the string for the first character that does NOT match the arguments
        // If none are found, there are only numbers
        // THis is needed to allow multidigit numbers and filter out garbage like "5a"
        if (str.find_first_not_of("0123456789", 1) == std::string::npos)
            return true;
    }
    return false;
}