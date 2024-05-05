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
