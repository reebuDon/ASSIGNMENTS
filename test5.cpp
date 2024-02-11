#include <iostream>
#include <chrono>
#include <vector>
#include <fstream>
#include "../src/Part 2.2/stackArr.cpp"
#include "../src/Part 2.2/queueArr.cpp"

using namespace std;

long long testStackPerformance(Stack<int> stack, int operations) 
{
    auto start = chrono::high_resolution_clock::now();
    
    // Perform a series of push operations
    for (int i = 0; i < operations; ++i) {
        stack.push(i);
    }

    // Perform a series of pop operations
    for (int i = 0; i < operations; ++i) {
        stack.pop();
    }

    auto end = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::microseconds>(end - start).count();
}

long long testQueuePerformance(Queue<int> queue, int operations) 
{
    auto start = chrono::high_resolution_clock::now();
    
    // Perform a series of enqueue operations
    for (int i = 0; i < operations; ++i) {
        queue.enqueue(i);
    }

    // Perform a series of dequeue operations
    for (int i = 0; i < operations; ++i) {
        queue.dequeue();
    }

    auto end = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::microseconds>(end - start).count();
}

int main()
{
    vector<int> testSizes = {10, 100, 1000, 10000, 50000, 100000, 150000};
    ofstream outFile("../src/Part 2.3/performance_results_Arr.csv");

    // Write CSV headers
    outFile << "Operations,Array Stack Time (microseconds),Array Queue Time (microseconds)\n";

    for (int operations : testSizes) {
        Stack<int> stack;
        Queue<int> queue;

        long long arrStackTime = testStackPerformance(stack, operations);
        long long arrQueueTime = testQueuePerformance(queue, operations);

        cout << "Operations: " << operations << "\n";
        cout << "Array Stack Time: " << arrStackTime << " microseconds\n";
        cout << "Array Queue Time: " << arrQueueTime << " microseconds\n";

        // Write to CSV file
        outFile << operations << "," << arrStackTime << "," << arrQueueTime << "\n";
    }

    outFile.close();
    cout << "Performance results written to performance_results.csv\n";

    return 0;
}