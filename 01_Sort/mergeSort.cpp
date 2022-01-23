#include <iostream>
#include <iterator>
#include <cstring>

using namespace std;

int merge(int *beg, int *mid, int *ed);

int process(int *beg, int *ed)
{
    if (beg == ed)
        return 0;

    int *mid = beg + ((ed - beg) >> 1);
    
    process(beg, mid);
    process(mid + 1, ed);
    merge(beg, mid, ed);
}

int merge(int *beg, int *mid, int *ed)
{
    int *helpOri = new int[ed - beg + 1];
    int *hp = helpOri;
    int *lp = beg;
    int *rp = mid + 1;

    while (lp <= mid && rp <= ed) {
        if (*lp <= *rp)
            *hp++ = *lp++;
        else
            *hp++ = *rp++;
    }

    while (lp <= mid)
        *hp++ = *lp++;

    while (rp <= ed)
        *hp++ = *rp++;

    memcpy(beg, helpOri, sizeof(int) * (ed - beg + 1));

    delete helpOri;
    return 0;
}

int mergeSort(int *arr, int *beg, int *ed)
{
    return process(beg, ed);
}

int main()
{
    int arr[7] = {0, 3, 1, 4, 7, 8, 3};

    mergeSort(arr, begin(arr), end(arr) - 1);

    for (auto num : arr)
        cout << num << endl;
    cout << endl;
}