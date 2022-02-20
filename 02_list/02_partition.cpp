#include <list>
#include <iostream>

using namespace std;

int main()
{
    list<int> box = {2, 3, 7, 9, 4, 1, 9, 3, 8, 7};
    list<int> small, equal, large;

    int target = 3;

    for (auto it = box.begin(); it != box.end(); ++it) {
        if (*it > target)
            large.push_back(*it);
        else if (*it == target)
            equal.push_back(*it);
        else if (*it < target)
            small.push_back(*it);
    } 

    small.splice(small.end(), equal);
    small.splice(small.end(), large);

    for (auto &it : small)
        cout << it << endl;

    return 0;
}