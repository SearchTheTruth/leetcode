#include <queue>
#include <functional>
#include <vector>
#include <iostream>


using std::priority_queue;
using std::greater;

int main()
{
    int arr[7] = {0, 3, 1, 4, 7, 8, 3};
    priority_queue<int> big;
    priority_queue<int, std::vector<int>, greater<int>> small;

    for (auto &it : arr) {
        small.push(it);
        if (small.size() - big.size() > 1) {
            big.push(small.top());
            small.pop();
        }
    }

    std::cout << "The middle value of stream as below" << std::endl;
    std::cout << "Maximun in Bigheap is " << big.top() << std::endl;
    std::cout << "Minimun in Smallheap is " << small.top() << std::endl;

    return 0;
}


//自己实现的大根堆和小根堆
#if 0
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

class HeapInfo {
public:
    virtual int pop() {
        return heapBuff[--realIdx];
    }
    virtual int top() {
        return heapBuff[0];
    }
protected:
    friend int operator-(const HeapInfo &l, const HeapInfo &r);
    int heapBuff[100] = {0};   //Heap默认能排序100个元素
    int realIdx = 0;           //Heap内实际存在的元素个数
};

class BigHeap : public HeapInfo {
public:
    int push_back(int element);
};

class SmallHeap : public HeapInfo {
public:
    int push_back(int element);
};

int operator-(const HeapInfo &l, const HeapInfo &r)
{
    return l.realIdx - r.realIdx;
}

int BigHeap::push_back(int element)
{
    int index = realIdx;
    heapBuff[realIdx] = element;
    while (heapBuff[index] > heapBuff[(index - 1) / 2]) {
        swap(heapBuff[index], heapBuff[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
    realIdx++;
    return 0;
}

int SmallHeap::push_back(int element)
{
    int index = realIdx;
    heapBuff[realIdx] = element;
    while (heapBuff[index] < heapBuff[(index - 1) / 2]) {
        swap(heapBuff[index], heapBuff[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
    realIdx++;
    return 0;
}
#endif
