class Solution
{
public:
    typedef pair<int, pair<int, int>> p;
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2,
                                       int k)
    {
        vector<vector<int>> v;
        priority_queue<p, vector<p>, greater<p>> pq;
        set<pair<int, int>> st;
        pq.push({nums1[0] + nums2[0], {0, 0}});
        st.insert({0, 0});
        while (k && !pq.empty())
        {
            auto x = pq.top();
            pq.pop();
            int i = x.second.first;
            int j = x.second.second;
            v.push_back({nums1[i], nums2[j]});
            if (i + 1 < nums1.size() && st.find({i + 1, j}) == st.end())
            {
                pq.push({nums1[i + 1] + nums2[j], {i + 1, j}});
                st.insert({i + 1, j});
            }
            if (j + 1 < nums2.size() && st.find({i, j + 1}) == st.end())
            {
                pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
                st.insert({i, j + 1});
            }
            k--;
        }
        return v;
    }
};