#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>

using namespace std;

struct Stack
{
    char sign;
    Stack *next;
} *top = nullptr;
bool isEmpty(Stack *top)
{
    return top == nullptr ? true : false;
}

Stack *push(Stack *tp, char sign)
{
    Stack *temp = new Stack;
    temp->sign = sign;
    if (tp == nullptr)
    {
        temp->next = nullptr;
    }
    else
    {
        temp->next = tp;
    }
    return temp;
}
char popp(Stack *tp)
{
    if (isEmpty(tp))
    {
        cout << "Stack is underflow (empty)";
        return '0';
    }
    else
    {
        Stack *temp = tp;
        top = top->next;
        char sign = temp->sign;
        free(temp);
        return sign;
    }
}

bool isOperator(char ch)

{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '&' || ch == '!' || ch == '|')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int getPrecedence(char ch)
{
    if (ch == '^')
    {
        return 6;
    }
    if (ch == '*' || ch == '/')
    {
        return 5;
    }
    else if (ch == '+' || ch == '-')
    {
        return 4;
    }
    else if (ch == '=' || ch == '!')
    {
        return 3;
    }
    else if (ch == '&')
    {
        return 2;
    }
    else if (ch == '|')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void LinkedListTraversal(Stack *top)
{
    while (top != nullptr)
    {
        top = top->next;
    }
}
char *AddInPostFix(const char inf, char *postfixExp)
{
    char infStr[2]; // Create a string to hold the character and null-terminator
    infStr[0] = inf;
    infStr[1] = '\0';
    strcat(postfixExp, infStr);
    return postfixExp;
}

const char *getPostFix(const char *inf)
{
    char *postfixExp = new char[100];
    char stackTop;
    for (const char *ptr = inf; *ptr != '\0'; ptr++)
    {
        const char singleInfChar = *ptr;
        bool isOpr = isOperator(singleInfChar);
        if (isOpr)
        {
            int precedence = getPrecedence(singleInfChar);
            while (!isEmpty(top))
            {
                stackTop = popp(top);
                if (stackTop != '0')
                {
                    int topPrec = getPrecedence(stackTop);

                    if (topPrec >= precedence)
                    {
                        postfixExp = AddInPostFix(stackTop, postfixExp);
                    }
                    else
                    {
                        top = push(top, stackTop);
                        break;
                    }
                }
            }
            top = push(top, singleInfChar);
        }
        else if (singleInfChar == '(')
        {
            top = push(top, singleInfChar);
        }
        else if (singleInfChar == ')')
        {
            while (!isEmpty(top))
            {
                stackTop = popp(top);
                if (stackTop == '(')
                    break;
                postfixExp = AddInPostFix(stackTop, postfixExp);
            }
        }
        else
        {
            postfixExp = AddInPostFix(singleInfChar, postfixExp);
        }
    }
    while (!isEmpty(top))
    {
        stackTop = popp(top);
        postfixExp = AddInPostFix(stackTop, postfixExp);
    }
    return postfixExp;
}
int main()
{
    const char *infix = "a+b*c/d-5*(x+56*d)";
    const char *postfix = getPostFix(infix);
    cout << "postfix is " << postfix << endl;
    return 0;
}