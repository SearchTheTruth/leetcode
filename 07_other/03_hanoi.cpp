#include <iostream>
#include <cstring>
#include <string>

using namespace std;

void process(int level, string src, string des, string oth)
{
    if (level == 1) {
        cout << "move 1 from " << src << " to " << des << endl;
        return;
    }

    process(level - 1, src, oth, des);
    cout << "move "<< level << " from " << src << " to " << des << endl;
    process(level - 1, oth, des, src);
    return;
}

void hanoi(int level)
{
    process(level, "left", "right", "mid");
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        cout << "parmeter illegal" << endl;
        return 0;
    }

    hanoi(atoi(argv[1]));

    return 0;
}