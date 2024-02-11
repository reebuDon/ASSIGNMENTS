#ifndef __BOOKMANAGER
#define __BOOKMANAGER

#include "LinkedList.h"
#include "stackLL.h"
#include <string>


/*WebPage Entry*/

struct WebPage
{
    string url;
    int load_time;
    int engagement_score; 

    WebPage()
    {}

    WebPage(string url,int load_time, int engagement_score)
    {
        this->load_time = load_time;
        this->engagement_score = engagement_score;
        this->url = url;
    }
};

/* This is the generic WebPageBrowser class */

class WebPageBrowser
{

  public:

    LinkedList<WebPage> list;
    Stack<WebPage> stack_1;
    Stack<WebPage> stack_2;


    // Constructor
    WebPageBrowser();

    // Copy Constructor
    WebPageBrowser(WebPageBrowser& otherStack);

    // Destructor
    ~WebPageBrowser();

    // Required Methods
    void push(WebPage item);
    WebPage top();
    WebPage pop();
    int length();
    bool isEmpty();
    WebPage fastestLoadTime();
    WebPage highestEngagement();

};

#endif