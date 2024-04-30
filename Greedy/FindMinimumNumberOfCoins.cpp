vector<int> MinimumCoins(int n)
{
    int arr[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int size = sizeof(arr) / sizeof(arr[0]);
    vector<int> v;
    for (int i = size - 1; i >= 0; i--)
    {
        while (n >= arr[i])
        {
            n -= arr[i];
            v.push_back(arr[i]);
        }
    }
    return v;
}
