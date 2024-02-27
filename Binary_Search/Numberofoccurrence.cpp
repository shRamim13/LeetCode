#include <algorithm>
#include <vector>

using namespace std;

int count(vector<int> &arr, int n, int k)
{
    int lb = lower_bound(arr.begin(), arr.end(), k) - arr.begin();
    int ub = upper_bound(arr.begin(), arr.end(), k) - arr.begin();

    if (lb == n || arr[lb] != k)
    {
        return 0;
    }
    return ub - lb;
}
