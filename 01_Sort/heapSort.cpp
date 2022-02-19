#include <iostream>

int swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
    return 0;
}

int heapIfy(int *arr, int idx, int heapSize)
{
    int left = idx * 2 + 1;
    
    while (left < heapSize) {
        int largetst = (left + 1 < heapSize && arr[left + 1] > arr[left]) ? left + 1 : left;
        largetst = arr [idx] > arr[largetst] ? idx : largetst;
        if (largetst == idx)
            break;
        swap(arr[idx], arr[largetst]);
        idx = largetst;
        left = idx * 2 + 1;
    }
    
    return 0;
}

int heapInsert(int *arr, int idx)
{
    while (arr[idx] > arr[(idx - 1) /2]) {
        swap(arr[idx], arr[(idx - 1) / 2]);
        idx = (idx - 1) / 2;
    }

    return 0;
}


int main()
{
    int arr[7] = {0, 3, 1, 4, 7, 8, 3};
    for (int i = 0; i < 7; i++)
        heapInsert(arr, i);

    int arrSize = 7;
    swap(arr[0], arr[--arrSize]);
    while (arrSize > 0) {
        heapIfy(arr, 0, arrSize);
        swap(arr[0], arr[--arrSize]);
    }

    for(auto &num : arr) 
        std::cout << num << std::endl;
    return 0;
}

