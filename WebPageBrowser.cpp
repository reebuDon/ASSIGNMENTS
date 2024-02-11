#include "../../include/WebPageBrowser.h"
#include <iostream>
// You aren't allowed to edit these method declarations or declare global variables

WebPageBrowser::WebPageBrowser()
{
}

WebPageBrowser::WebPageBrowser(WebPageBrowser& otherStack)
{
    list = otherStack.list;
    stack_2 = otherStack.stack_2;
    stack_1 = otherStack.stack_1;
}

WebPageBrowser::~WebPageBrowser()
{}

void WebPageBrowser::push(WebPage item)
{
    if(stack_1.isEmpty())
    {
        stack_1.push(item);stack_2.push(item);list.insertAtHead(item);
    }
    else
    {
        stack_1.push(item);
        WebPage min_T = stack_2.top();shared_ptr<ListItem<WebPage>> max_Ep = list.getHead();
        WebPage max_E = max_Ep->value;
        if(item.engagement_score>=max_E.engagement_score)
        {
            list.insertAtHead(item);
        }
        if(item.load_time<=min_T.load_time)
        {
            stack_2.push(item);
        }

    }
}

WebPage WebPageBrowser::top() 
{
    return stack_1.top();
}

WebPage WebPageBrowser::pop()
{
    WebPage magicPage = stack_1.pop();
    WebPage min_T = stack_2.top();shared_ptr<ListItem<WebPage>> max_Ep = list.getHead();
    WebPage max_E = max_Ep->value;
    if(magicPage.engagement_score>=max_E.engagement_score)
    {
        list.deleteHead();
    }
    if(magicPage.load_time<=min_T.load_time)
    {
        stack_2.pop();
    }
    return magicPage;
}
int WebPageBrowser::length() 
{
    return stack_1.length();
}

bool WebPageBrowser::isEmpty() 
{
    return stack_1.isEmpty();
}

WebPage WebPageBrowser::highestEngagement() // Must be implemented in O(1)
{
    shared_ptr<ListItem<WebPage>> a = list.getHead();
    WebPage b = a->value;
    return b;
}

WebPage WebPageBrowser::fastestLoadTime() // Must be implemented in O(1)
{
    return stack_2.pop();
}


