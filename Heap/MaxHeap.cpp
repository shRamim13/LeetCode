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

    // Increase key value of key at index i to new_val
    void increaseKey(int i, int new_val);

    // Get the maximum key (key at root) from max heap
    int getMax() { return harr[0]; }

    // Delete a key stored at index i
    void deleteKey(int i);

    // Insert a new key 'k'
    void insertKey(int k);
};

// Constructor: Builds a heap from a given array a[] of given size
MaxHeap::MaxHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}

// Inserts a new key 'k'
void MaxHeap::insertKey(int k)
{
    if (heap_size == capacity)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    // First insert the new key at the end
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;

    // Fix the max heap property if it is violated
    while (i != 0 && harr[parent(i)] < harr[i])
    {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

// Increases value of key at index 'i' to new_val. It is assumed that
// new_val is greater than harr[i].
void MaxHeap::increaseKey(int i, int new_val)
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] < harr[i])
    {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

// Method to remove maximum element (or root) from max heap
int MaxHeap::extractMax()
{
    if (heap_size <= 0)
        return INT_MIN;
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }

    // Store the maximum value, and remove it from heap
    int root = harr[0];
    harr[0] = harr[heap_size - 1];
    heap_size--;
    MaxHeapify(0);

    return root;
}

// Deletes key at index i
void MaxHeap::deleteKey(int i)
{
    increaseKey(i, INT_MAX);
    extractMax();
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

// Driver program to test above functions
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
    cout << h.extractMax() << " ";
    cout << h.getMax() << " ";
    h.increaseKey(2, 1);
    cout << h.getMax();
    return 0;
}
