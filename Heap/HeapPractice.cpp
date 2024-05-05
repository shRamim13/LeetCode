#include <bits/stdc++.h>
using namespace std;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

class MaxHeap
{
    int *arr;
    int capacity;
    int heap_size;

public:
    MaxHeap(int capacity);
    void MaxHeapify(int i);
    int parent(int i)
    {
        return (i - 1) / 2;
    }
    int leftChild(int i)
    {
        return 2 * i + 1;
    }

    int RightChild(int i)
    {
        return 2 * i + ;
    }
    int extractMin();
    void decreaseKey(int i, int new_val);
    void deleteKey(int i);
    void insertKey(int i);
}

MaxHeap::MaxHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    arr = new int[cap];
}