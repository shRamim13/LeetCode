#include <iostream>
#include <climits>
using namespace std;

// Utility function to swap two integers
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

// Class for Max Heap
class MaxHeap
{
    int *harr;     // Pointer to array of elements in heap
    int capacity;  // Maximum possible size of max heap
    int heap_size; // Current number of elements in max heap
public:
    // Constructor
    MaxHeap(int capacity);

    // Utility function to heapify a subtree with the root at given index
    void MaxHeapify(int i);

    int parent(int i) { return (i - 1) / 2; } // Parent of a node
    int left(int i) { return (2 * i + 1); }   // Left child of a node
    int right(int i) { return (2 * i + 2); }  // Right child of a node

    // Extract the root which is the maximum element
    int extractMax();

    // Get the maximum key (key at root) from max heap
    int getMax() { return harr[0]; }

    // Heap sort function
    void heapSort();
};

// Constructor: Builds a heap from a given array a[] of given size
MaxHeap::MaxHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}

// Method to remove maximum element (or root) from max heap
int MaxHeap::extractMax()
{
    if (heap_size <= 0)
        return INT_MIN;

    // Store the maximum value, and remove it from heap
    int root = harr[0];
    harr[0] = harr[heap_size - 1];
    heap_size--;
    MaxHeapify(0);

    return root;
}

// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void MaxHeap::MaxHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int largest = i;
    if (l < heap_size && harr[l] > harr[i])
        largest = l;
    if (r < heap_size && harr[r] > harr[largest])
        largest = r;
    if (largest != i)
    {
        swap(harr[i], harr[largest]);
        MaxHeapify(largest);
    }
}

// Heap Sort function
void MaxHeap::heapSort()
{
    // Build max heap
    for (int i = heap_size / 2 - 1; i >= 0; i--)
        MaxHeapify(i);

    // Extract elements from the heap one by one
    for (int i = heap_size - 1; i > 0; i--)
    {
        // Move current root to end
        swap(harr[0], harr[i]);

        // Call max heapify on the reduced heap
        MaxHeapify(0);
    }
}

// Driver program to test Heap Sort
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    MaxHeap heap(n);
    for (int i = 0; i < n; i++)
        heap.insertKey(arr[i]);

    heap.heapSort();

    cout << "Sorted array is \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
