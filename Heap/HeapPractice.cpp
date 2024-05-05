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
    int getMax()
    {
        return arr[0];
    }
    void insertKey(int i);
};

MaxHeap::MaxHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    arr = new int[cap];
}

void MaxHeap::insertKey(int k)
{
    if (heap_size == capacity)
    {
        cout << "\nOverFlow: Could not insertKey\n";
        return;
    }
    heap_size++;
    int i = heap_size - 1;
    arr[i] = k;
    while (i != 0 && arr[parent(i)] < arr[i])
    {
        swap(arr[parent(i)], arr[i]);
        i = parent(i);
    }
}

void MaxHeap::decreaseKey(int i, int new_val)
{
    arr[i] = new_val;
    while (i != 0 && arr[parent(i)] < arr[i])
    {
        swap(arr[parent(i)], arr[i]);
        i = parent(i);
    }
}

int MaxHeap::extractMin()
{
    if (heap_size <= 0)
    {
        return INT_MIN;
    }
    if (heap_size == 1)
    {
        heap_size--;
        return arr[0];
    }
    int root = arr[0];
    arr[0] = arr[heap_size - 1];
    heap_size--;
    MaxHeapify(0);
    return root;
}
void MaxHeap::deleteKey(int i)
{
    decreaseKey(i, );
    cout << extractMin() << " is deleted from heap \n";
}

void MaxHeap::MaxHeapify(int i)
{
    int lt = leftChild(i);
    int rt = RightChild(i);
    int largest = i;
    if (lt < heap_size && arr[lt] > arr[largest])
    {
        largest = lt;
    }
    if (rt < heap_size && arr[rt] > arr[largest])
    {
        largest = rt;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        MaxHeapify(largest);
    }
}

int main()
{
    MaxHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.extractMin() << " ";
    cout << h.getMax() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMax();
    return 0;
}