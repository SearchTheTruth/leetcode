#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>

using namespace std;

int infect(int (*isLand)[6], int x, int y, int xMax, int yMax)
{
    if (isLand[y][x] == 0)
        return 0;

    if (isLand[y][x] == 2)
        return 0;

    isLand[y][x] = 2;

    if (x - 1 >= 0)
        infect(isLand, x - 1, y, xMax, yMax);
    if (x + 1 < xMax)
        infect(isLand, x + 1, y, xMax, yMax);
    if (y - 1 >= 0)
        infect(isLand, x, y - 1, xMax, yMax);
    if (y + 1 < yMax)
        infect(isLand, x, y + 1, xMax, yMax);

    return 1;
}

int dumpIsLand(int (*isLand)[6], int xMax, int yMax)
{
    cout << "+++++++++++++++++" << endl;
    for(int y = 0; y < yMax; ++y) {
        for (int x = 0; x < xMax; ++x) {
            cout << isLand[y][x] << "\t";
        }
        cout << endl;
    }
    cout << "+++++++++++++++++" << endl;

    return 0;
}

int findLand(int (*isLand)[6], int xMax, int yMax)
{
    int cnt = 0;
    dumpIsLand(isLand, xMax, yMax);
    for (int y = 0; y < yMax; ++y) {
        for (int x = 0; x < xMax; ++x) {
            if (isLand[y][x] == 1) {
                cnt++;
                infect(isLand, x, y, xMax, yMax);
                dumpIsLand(isLand, xMax, yMax);
            }
        }
    }
    return cnt;
}

int main()
{
    int isLand[4][6] = {{0, 0, 1, 0, 1, 0},
                        {1, 1, 1, 0, 1, 0},
                        {1, 0, 0, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0},
                       };

    cout << findLand(isLand, 6, 4) << endl;
    return 0;
}