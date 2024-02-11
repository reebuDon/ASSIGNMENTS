#include "../../include/mathGauge.h"

// You aren't allowed to edit these method declarations or declare global variables
// .....................................................................................

mathGauge::mathGauge(string expression)
{
    totalCount = expression.length();
}

void mathGauge::populateStack(string expression)
{
    totalCount = expression.length();
    for (int i = 0; i < totalCount; i++)
        stack_1.push(expression[totalCount - 1 - i]);
}

void mathGauge::populateQueue(string* names, int len)
{
    for (int i = 0; i < len; i++)
        lane_1.enqueue(names[i]);
}

void mathGauge::assemble(Stack<char> results)
{
    string exp = "";
    shared_ptr<IntegronExpressions> ptr;

    while (!results.isEmpty())
        exp = results.pop() + exp;
    
    storeResults.enqueue(make_shared<IntegronExpressions>(exp, exp.length()));
    resetStack();
}

// .....................................................................................
// To Implement

bool mathGauge::isBalancedExpression(Stack<char> tempStack)
{
    char specialVariable;
    while(!(stack_1.isEmpty()))
    {
        specialVariable=stack_1.top();
        if(specialVariable=='('||specialVariable=='{'||specialVariable=='[')
        {
            tempStack.push(stack_1.pop());
        }
        else if(specialVariable==')'||specialVariable=='}'||specialVariable==']')
        {
            if(tempStack.isEmpty())
            {
                return 0;
            }
            else
            {
                switch(specialVariable)
                {
                    case ')':
                    if (tempStack.top()=='(')
                    {
                        tempStack.pop();stack_1.pop();
                    }
                    else return 0; break;
                     case '}':
                    if (tempStack.top()=='{')
                    {
                        tempStack.pop();stack_1.pop();
                    }
                    else return 0; break; case ']':
                    if (tempStack.top()=='[')
                    {
                        tempStack.pop();stack_1.pop();
                    }
                    else return 0; break;
                    default:
                    return 0; break;
                }
            }
        }
        else stack_1.pop();
    }
    return 1;
}

int mathGauge::helperFunction(char word)
{
    return 0;
}

Stack<char> mathGauge::stub(Stack<char> tempStack1, Stack<char> tempStack2)
{}

void mathGauge::generateOutput()
{}

void mathGauge::resetStack()
{
    Stack<char> empty;
    stack_1 = empty;
}

void mathGauge::reverseQueue(Queue<string> lane_2)
{
    while(lane_1.length()>1)
      {
        lane_2.enqueue(lane_1.dequeue());
      }
      while(!(lane_2.isEmpty()))
      {
        for(int i = 1;i<lane_2.length();i++)
        {
            lane_2.enqueue(lane_2.dequeue());
        }
        lane_1.enqueue(lane_2.dequeue());
      }
}
