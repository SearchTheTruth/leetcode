#include <iostream>
#include <iterator>
#include <utility>
#include <random>

using namespace std;

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void randomSwap(int*left, int *right)
{
    default_random_engine generator;
    uniform_int_distribution<int> distribution(0, right - left);
    int random = distribution(generator);
    swap(left + random, right);
}

pair<int*, int*> partition(int *arr, int *left, int *right)
{
    int target = *right;    //每次都用最右侧的值作为相等区域的目标值
    int *lessR = left - 1;
    int *moreL = right;
    int *i = left;

    while (i < moreL) {
       if (*i > target) {
          swap(i, moreL - 1);
          moreL--;          //左扩张大于区域
       } else if (*i == target) {
           i++;
       } else if (*i < target) {
           swap(i, lessR + 1);
           lessR++;        //右扩张小于区域
           i++;
       }
    }
    swap(moreL--, right);  //因为开始将target放在了大于区域，占据一个空间，所以将target放回等于区域的同时退还空间
    return make_pair(lessR + 1, moreL);   //返回等于区域的左右边界
}

int quickSort(int *arr, int *left, int *right)
{
    if (left == right)
        return 0;

//  randomSwap(left, right);      //该函数在left~right间随机选取一个位置的数字，与最右侧数字交换
    pair<int *, int*> range = partition(arr, left, right);
    quickSort(arr, left, range.first - 1);
    quickSort(arr, range.second + 1, right);
}

int main()
{
    int arr[7] = {0, 3, 1, 4, 7, 8, 3};

    quickSort(arr, begin(arr), end(arr) - 1);

    for(auto &num : arr) 
        cout << num << endl;

    return 0;
}