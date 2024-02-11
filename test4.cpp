#include <iostream>
#include <chrono>
#include <vector>
#include <fstream>
#include "../src/Part 2.1/stackLL.cpp"
#include "../src/Part 2.1/queueLL.cpp"
#include "../src/Part 1/LinkedList.cpp"

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
    ofstream outFile("../src/Part 2.3/performance_results_LL.csv");

    // Write CSV headers
    outFile << "Operations,LinkedList Stack Time (microseconds),LinkedList Queue Time (microseconds)\n";

    for (int operations : testSizes) {
        Stack<int> stack;
        Queue<int> queue;

        long long llStackTime = testStackPerformance(stack, operations);
        long long llQueueTime = testQueuePerformance(queue, operations);

        cout << "Operations: " << operations << "\n";
        cout << "LinkedList Stack Time: " << llStackTime << " microseconds\n";
        cout << "LinkedList Queue Time: " << llQueueTime << " microseconds\n";

        // Write to CSV file
        outFile << operations << "," << llStackTime << "," << llQueueTime << "\n";
    }

    outFile.close();
    cout << "Performance results written to performance_results.csv\n";

    return 0;
}