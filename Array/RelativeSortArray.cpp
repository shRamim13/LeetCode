class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        unordered_map<int, int> mp;
        unordered_map<int, int> hash;
        for (int i = 0; i < arr1.size(); i++)
        {
            mp[arr1[i]]++;
        }

        vector<int> ans;
        vector<int> remaining;
        for (auto x : arr2)
        {
            int b = mp[x];
            while (b--)
            {
                ans.push_back(x);
            }
            mp.erase(x);
        }
        for (auto x : mp)
        {
            int a = x.first;
            int b = x.second;
            while (b--)
            {
                remaining.push_back(a);
            }
        }
        sort(remaining.begin(), remaining.end());
        for (auto x : remaining)
        {
            ans.push_back(x);
        }
        return ans;
    }
};
