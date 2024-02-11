#ifndef MATHGAUGE_H
#define MATHGAUGE_H
#include "../src/Part 2.2/stackArr.cpp"
#include "../src/Part 2.2/queueArr.cpp"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

// This struct just holds the final expression which is understandable to Integron. You aren't allowed to edit this
// ...............................................
struct IntegronExpressions
{
    string expression;
    int length;

    IntegronExpressions(string expression, int len)
    {
        this->expression = expression;
        this->length = len;
    }   
};
// ...............................................

class mathGauge{

    public:

    Stack<char> stack_1;

    Queue<string> lane_1;

    int totalCount;        //store the total number of letters
    char specialVariable;   // read manual to find out where it's useful

    // You aren't allowed to edit these methods
    // ...............................................
    mathGauge(string expression);
    void populateStack(string expression); 
    void populateQueue(string* names, int len);  
    void assemble(Stack<char> results);
    void resetStack();
    // ...............................................

    bool isBalancedExpression(Stack<char> tempStack);    

    Stack<char> stub(Stack<char> tempStack1, Stack<char> tempStack2);

    void reverseQueue(Queue<string> lane_2);

    void generateOutput();

    private:

    Queue<shared_ptr<IntegronExpressions>> storeResults;

    int helperFunction(char word); // you aren't allowed to edit the function's parameter and return type (Hint: read manual)
};



#endif