#include "../src/Part 4/mathGauge.cpp"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

float totalmarks = 0, testpoints = 0;

float test_balance_helper(const string& category, const string testCases[], const bool expectedResults[], int numTests, int marks) 
{
    cout << "Running " << category << " tests:" << endl;
    float count = 0;

    for (int i = 0; i < numTests; ++i) 
    {
        mathGauge tester(testCases[i]);  // Instantiate mathGauge with the expression
        tester.populateStack(testCases[i]);  // Populate the stack with the expression characters
        Stack<char> tempStack;

        bool result = tester.isBalancedExpression(tempStack);  // Pass an empty Stack<char> to the method
        cout << "  Test " << i + 1 << " (Expression: " << testCases[i] << "): " 
                  << (result == expectedResults[i] ? "Passed" : "Failed") << endl;
        if (result == expectedResults[i])
            count += (float) marks / numTests;
    }

    cout << "\033[32m";
    cout << "  Marks Obtained: " << count << " / " <<  marks << endl;
    cout << "\033[0m";

    return count;
}

void test_balance() 
{
    // Easy tests
    string easyTestCases[] = {"{[([({})])]}}", "abc123", "[[[[[[[]]]]]]]]", "{[(])}", "(([[{{}}]]))"};
    bool easyExpectedResults[] = {false, true, false, false, true};
    totalmarks += test_balance_helper("Easy", easyTestCases, easyExpectedResults, 5, 1);

    // Medium tests
    string mediumTestCases[] = {"{[()]}", "{[]()}", "{[(){}[]]}", "[([]])", "{[()()][]}"};
    bool mediumExpectedResults[] = {true, true, true, false, true};
    totalmarks += test_balance_helper("Medium", mediumTestCases, mediumExpectedResults, 5, 2);

    // Hard tests
    string hardTestCases[] = {"{[(])}", "{[()}", "{[()()]}]", "{[{()()}([])]}", "ab{c[1(23)]}"};
    bool hardExpectedResults[] = {false, false, false, true, true};
    totalmarks += test_balance_helper("Hard", hardTestCases, hardExpectedResults, 5, 2);

    cout << "\033[34m";
    cout << "Total Score: " << totalmarks << " / 5\n";
    cout << "\033[0m";
}

void test_integron_helper2(int filenum, int marks)
{
   	fstream f1, f2;
    string s1, s2;
    float count = 0;

    f1.open("answers" + to_string(filenum) + ".txt",ios::in);
    f2.open("output.txt",ios::in);
    getline(f1, s1);
    getline(f2, s2);
    int length = stoi(s1);

    for (int i = 2; i <= length + 1; i++)
    {
        getline(f1, s1);
        getline(f2, s2);

        if(s1 == s2)
            count += (float) marks / filenum;
        else
            cout << "  " << i << ": RESULT: " << s2 << " EXPECTED: " << s1 << endl;
    }

    testpoints += count;

    f1.close();
    f2.close();

    cout << "\033[32m";
    cout << "  Marks Obtained: " << count << " / " << marks << endl;
    cout << "\033[0m";
}

void test_integron_helper1(int filenum, int marks)
{
    fstream f1;
    string s1;
    mathGauge m1(s1);

    f1.open("expressions" + to_string(filenum) + ".txt",ios::in);
    getline(f1, s1);
    int length = stoi(s1);

    for (int i = 1; i <= length; i++)
    {
        getline(f1, s1);

        m1.populateStack(s1);


        Stack<char> tempStack1, tempStack2, result;
        result = m1.stub(tempStack1, tempStack2);

        m1.assemble(result);
    }

    m1.generateOutput();

    f1.close();

    test_integron_helper2(filenum, marks);
}

void test_integron()
{
    cout << "\nIntegron interpreting expressions:\n";
    cout << "  Test 1: expressions10.txt: " << endl; 
    test_integron_helper1(10, 5);
    cout << "  Test 2: expressions32.txt: " << endl; 
    test_integron_helper1(32, 7);
    cout << "  Test 3: expressions50.txt: " << endl; 
    test_integron_helper1(50, 8);

    cout << "\033[34m";
    cout << "Total Score: " << testpoints << " / 20\n";
    cout << "\033[0m";

    totalmarks += testpoints;
}

string rand_string_generator(int length)
{
    string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string randomString;

    for (int i = 0; i < length; ++i) 
    {
        int index = rand() % characters.length();  // Get a random index
        randomString += characters[index];  // Append the character at the index
    }

    return randomString;
}

void test_reverse_queue(float marks)
{
    cout << "Testing Reverse Queue: ";
    const int SIZE = 150;
    testpoints = 0;
    string arr[SIZE], reverseArr[SIZE];

    srand(time(0));

    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = rand_string_generator(4);
        reverseArr[SIZE - i - 1] = arr[i];
    }

    mathGauge m1("");
    Queue<string> q2;
    int flag = 0, i = 0;

    m1.populateQueue(arr, SIZE);
    m1.reverseQueue(q2);

    while (!q2.isEmpty())
    {
        if (q2.dequeue() == reverseArr[i])
            flag = 1;
    }

    if (flag)
        cout << "Test Failed\n";
    else
    {
        cout << "Test Passed\n";
        testpoints += marks;
    }
    
    cout << "\033[34m";
    cout << "Total Score: " << testpoints << " / " << marks << endl;
    cout << "\033[0m";

    totalmarks += testpoints;
}

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        test_balance();
        test_integron();
        test_reverse_queue(10);

        cout << "\033[31m";
        cout << "\nFinal Score: " << totalmarks << " / 35\n";
        cout << "\033[0m";
    }
    else
    {
        int choice = stoi(argv[1]);
        switch(choice)
        {
        case 1:
            test_reverse_queue(10);
            break;
        
        case 2:
            test_balance();
            break;
        
        case 3:
            test_integron();
            break;
        
        default:
            cout << "Incorrect input\n";
            break;
        }
    }
}