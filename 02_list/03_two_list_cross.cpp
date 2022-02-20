#include <list>
#include <iostream>
#include <set>

using namespace std;

list<int>::iterator hasRing(list<int> test)
{
    set<int> help;
    list<int>::iterator it;

    for (it = test.begin(); it != test.end(); ++it) {
        if (help.find(*it) == help.end())
            help.insert(*it);
        else
            break;
    }
    return it;
}

