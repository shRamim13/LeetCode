int findKRotation(vector<int> &arr)
{
    int mini = arr[0];
    int l = 0;
    int r = arr.size() - 1;
    int indx = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[l] <= arr[r])
        {
            if (arr[l] < mini)
            {
                indx = l;
            }
            break;
        }
        if (arr[l] <= arr[mid])
        {
            if (arr[l] < mini)
            {
                indx = l;
            }
            l = mid + 1;
        }
        else
        {
            if (arr[mid] < mini)
            {
                indx = mid;
            }
            r = mid - 1;
        }
    }
    return indx;
}