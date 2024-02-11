#include "../src/Part 3/WebPageBrowser.cpp"
#include "../src/Part 2.1/stackLL.cpp"
#include "../src/Part 1/LinkedList.cpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include <thread>
#include <chrono>
#include <future>
#include <memory>

using namespace std;

bool timeOut;
promise<bool> done;

void timer(future<bool> done_future)
{
    std::chrono::seconds span(3);
    if (done_future.wait_for(span) == std::future_status::timeout)
    {
        timeOut = true;
    }
}

double test(promise<bool> done_future)
{
    using namespace std::chrono;
    WebPage a("kruskal.com",44,46);
    WebPage b("euler.com",31,29);
    WebPage c("permutations.com",67,78);
    WebPage d("relations.com",20,93);
    WebPage e("ilovegraphs.com",9,99);

    WebPageBrowser myStack;

    double score = 0;

    cout << "Starting Tests" << endl;
    cout << "\nTest 1: ";

    high_resolution_clock::time_point timeStart = high_resolution_clock::now();

    myStack.push(a);
    myStack.push(b);
    myStack.push(c);

    if (myStack.fastestLoadTime().load_time!=31)
    {
        cout << "Failed! Incorrect WebPage returned\n" << endl;
        return score;
    }
    if (myStack.highestEngagement().engagement_score!=78)
    {
        cout << "Failed! Incorrect WebPage returned\n" << endl;
        return score;
    }

    myStack.push(d);

    if (myStack.fastestLoadTime().load_time!=20)
    {
        cout << "Failed! Incorrect WebPage returned\n" << endl;
        return score;
    }
    if (myStack.highestEngagement().engagement_score!=93)
    {
        cout << "Failed! Incorrect WebPage returned\n" << endl;
        return score;
    }

    myStack.pop();
    myStack.pop();

    if (myStack.fastestLoadTime().load_time!=31)
    {
        cout << "Failed! Incorrect WebPage returned\n" << endl;
        return score;
    }
    if (myStack.highestEngagement().engagement_score!=46)
    {
        cout << "Failed! Incorrect WebPage returned\n" << endl;
        return score;
    }

    myStack.push(e);

    if (myStack.fastestLoadTime().load_time!=9)
    {
        cout << "Failed! Incorrect WebPage returned\n" << endl;
        return score;
    }
    if (myStack.highestEngagement().engagement_score!=99)
    {
        cout << "Failed! Incorrect WebPage returned\n" << endl;
        return score;
    }

    cout <<" Passed!\n";
    score+=5;

    cout << "\nTest 2: ";


    //Checks whether all functions are running in O(1)
   

    int tester_pub = 10000000;
    int tester_pop = -10000000;

    WebPageBrowser myStack2;

    for (int i = 0; i < 100000; i++) 
    {
        int load_time = ((rand() % (2024 - 1600 + 1)) + 1600);
        int engagement_score = ((rand() % 100));

        if(load_time < tester_pub)
        {
            tester_pub = load_time;
        }
        if(engagement_score > tester_pop)
        {
            tester_pop = engagement_score;
        }

        
        myStack2.push(WebPage("xyz",load_time,engagement_score));

        if(myStack2.fastestLoadTime().load_time!=tester_pub)
        {
            cout << "Failed! Incorrect WebPage returned" << endl;
            return score;
        }
        if(myStack2.highestEngagement().engagement_score!=tester_pop)
        {
            cout << "Failed! Incorrect WebPage returned" << endl;
            return score;
        }

        if (timeOut)
        {
            cout << "Failed! The test timed out." << endl;
            return score;
        }

    }

    for (int i=0; i < 100000; i++)
    {
        myStack2.pop();

        if (timeOut)
        {
            cout << "Failed! The test timed out." << endl;
            return score;
        }
    }

  
    score += 20;
    cout << " Passed!\n" << endl;

    done_future.set_value(true);
    high_resolution_clock::time_point timeEnd = high_resolution_clock::now();
    duration<double> totalTime = duration_cast<duration<double>>(timeEnd - timeStart);

    cout << "\nTest Passed in: " << totalTime.count() << " seconds." << endl;
    return score;
}




int main()
{

    srand(time(NULL));
    ifstream file;

    timeOut = false;

    future<bool> done_future = done.get_future();
    thread first(timer, std::move(done_future));
    double score = test(std::move(done));
    first.join();

    cout << "Total Score: " << score << "/25" << endl;

    return 0;
}