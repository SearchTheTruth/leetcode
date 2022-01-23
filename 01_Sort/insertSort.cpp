#include <iostream>
#include <iterator>

using namespace std;

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int inserSort_1(int *arr, int length) 
{
    for(int idx = 0; idx < length; idx++) {
        int tmpidx = idx;
        for(int pre = tmpidx - 1; pre >= 0; pre--) {
            if (arr[pre] <= arr[tmpidx]) {
                break;
            } else {
                swap(&arr[pre], &arr[tmpidx]);
                tmpidx = pre;
            }
        }
    }
    return 0;
}

int inserSort_2(int *arr, int length) 
{
    for(int idx = 0; idx < length; idx++) {
       for (int pre = idx - 1; pre >= 0 && arr[pre] > arr[pre + 1]; pre--) {
           swap(&arr[pre], &arr[pre + 1]);
       }
    }
    return 0;
}

int main()
{
    int arr[7] = {0, 3, 1, 4, 7, 8, 3};
    int arr2[7] = {0, 3, 1, 4, 7, 8, 3};

    inserSort_1(arr, 7);

    for (auto num : arr) {
        cout << num << endl;
    }

    cout << "insertSort_1 done" << endl;

    inserSort_2(arr2, 7);

    for (auto num : arr2) {
        cout << num << endl;
    }


    cout << "insertSort_2 done" << endl;
    return 0;
}