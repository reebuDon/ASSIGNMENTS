#include <iostream>
#include <string>
#include <sys/param.h>
#include <unistd.h>
#include <iomanip> 

using namespace std;

int interface() 
{
    const char* parts[] = {"Exit", "Linked Lists", "Stack and Queue (Linked List)", "Stack and Queue (Array)", "Graphical Analysis", "Web Pages Mayhem", "Reversing Queue", "Balanced Stacks", "Stub Design"};
    const double marks[] = {0, 15, 15, 5, 5, 25, 10, 5, 20};
    int input;

    // Print the header
    cout << string(90, '-') << endl;
    cout << left << setw(30) << "Index" << setw(50) << "Part" << setw(10) << "Marks" << endl;
    cout << string(90, '-') << endl;

    // Iterate and print each part with its index and marks
    for (size_t i = 0; i < sizeof(parts) / sizeof(parts[0]); ++i) 
        cout << left << setw(30) << i << setw(50) << parts[i] << setw(10) << marks[i] << endl;
    cout << string(90, '-') << endl;

    cout << "Enter the index of the test that you want to run: ";
    cin >> input;

    return input;
}

void start() 
{
    chdir("test");
    int flag = 1;

    while (flag)
    {
        switch (interface()) 
        {
        case 0:
            cout << "Exiting...\n";
            flag = 0;
            break;

        case 1:
            cout << endl;
            system("g++ test1.cpp -std=c++11 -Wno-div-by-zero && ./a.out");
            break;
        
        case 2:
            cout << endl;
            system("g++ test2.cpp -std=c++11 -Wno-div-by-zero && ./a.out");
            break;

        case 3:
            cout << endl;
            system("g++ test3.cpp -std=c++11 -Wno-div-by-zero && ./a.out");
            break;
        
        case 4:
            cout << endl;
            system("g++ test4.cpp -std=c++11 && ./a.out");
            cout << endl;
            system("g++ test5.cpp -std=c++11 && ./a.out");
            cout << endl;
            chdir("../src/Part 2.3");
            system("python3 graphs.py");
            cout << "Graphs ave successfully\n";
            chdir("../../test");
            break;

        case 5:
            cout << endl;
            system("g++ test6.cpp -std=c++11 && ./a.out");
            break;

        case 6:
            cout << endl;
            system("g++ test7.cpp -std=c++11 && ./a.out 1");
            break;
        
        case 7:
            cout << endl;
            system("g++ test7.cpp -std=c++11 && ./a.out 2");
            break;
        
        case 8:
            cout << endl;
            system("g++ test7.cpp -std=c++11 && ./a.out 3");
            break;

        default:
            cout << "No such test exists\n";
            break;
        }
    }
}

int main()
{
    start();

    return 0;
}