#include <list>
#include <stack>
#include <iostream>

using namespace std;

int isTenet(list<int> &test)
{
    auto fp = test.begin();
    auto sp = test.begin();
    stack<int> stk;
    //bool even = false;
    while (++fp != test.end()) {
        //fp mv forward
        ++fp;
        if (fp == test.end()) {
            //even = true;
            break;
        }
        //sp mv forward
        ++sp;
    }

    while(++sp != test.end())
        stk.push(*sp);

    auto beg = test.begin();
    while(!stk.empty()) {
        if (stk.top() != *(beg++))
            return 0;
        stk.pop();
    }
    return 1;
}

int main ()
{
    list<int> tenet_1 = {1, 2, 2, 3, 4, 4, 3, 2, 2, 1};    
    list<int> tenet_2 = {1, 2, 2, 3, 4, 3, 2, 2, 1};    
    list<int> tenet_3 = {1, 1};    
    list<int> tenet_4 = {1};    
    list<int> untenet = {1, 2, 3, 4, 5, 6, 7, 8, 9};


    cout << "tenet_1 " << isTenet(tenet_1) << endl;
    cout << "tenet_2 " << isTenet(tenet_2) << endl;
    cout << "tenet_3 " << isTenet(tenet_3) << endl;
    cout << "tenet_4 " << isTenet(tenet_4) << endl;
    cout << "untenet " << isTenet(untenet) << endl;

    return 0;
}