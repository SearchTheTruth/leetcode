#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

class Record {
public:
    Record(int n) : bound(n) {
        record = new int[n]();
    }

    Record(const Record &r) {
        *this = r;
    }

    ~Record() {
        delete []record;
    }

    Record &operator=(const Record& r) {
        bound = r.bound;
        record = new int[bound]();
        memcpy(record, r.record, bound*sizeof(int));   
        return *this;
    }

    int &operator[](int n) {
        if (n >= bound)
            cout << "ERROR: cross bound" << endl;
        return record[n];
    }
private:
    int bound;
    int *record;
};

//根据已有的棋子判断在x，y位置落子是否可行
bool isVaild(Record record, int x, int y)
{
    for (int k = 0; k < y; ++k)
        if (record[k] == x || abs(y - k) == abs(x - record[k]))
            return false;

    return true;
}

//记录已经放置的棋子数组下标代表行数，数值代表列数; 行数; 棋盘大小
int process(Record record, int y, int n)
{
    int res = 0;

    if (y == n)                  //该条路径可行
        return 1;

    for(int x = 0; x < n; ++x) {
        if (isVaild(record, x, y)) {
            record[y] = x;
            res += process(record, y + 1, n);
        }
    }
    return res;
}

int calculate_queen(int n)
{
    Record record(n);
    return process(record, 0, n);
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        cout << "parmeter illegal" << endl;
        return 0;
    }


    int n = calculate_queen(atoi(argv[1]));
    cout << argv[1] << "*" << argv[1] << ": have " << n << " ways to location" << endl;

    return 0;
}