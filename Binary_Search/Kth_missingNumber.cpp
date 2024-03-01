
class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int l = 0;
        int r = arr.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if ((arr[mid] - (mid + 1)) < k)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return r + k + 1;
    }
};

// class Solution
// {
// public:
//     int findKthPositive(vector<int> &arr, int k)
//     {
//         for (int i = 0; i < arr.size(); i++)
//         {
//             if (arr[i] <= k)
//                 k++;
//             else
//                 break;
//         }
//         return k;
//     }
// };