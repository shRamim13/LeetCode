class Solution
{
public:
    unordered_map<string, vector<pair<string, double>>> mp;
    void solve(string src, string des, double &ans, double val,
               unordered_set<string> &st)
    {
        if (st.find(src) != st.end())
        {
            return;
        }
        st.insert(src);
        if (src == des)
        {
            ans = val;
            return;
        }
        for (auto x : mp[src])
        {
            string v = x.first;
            double wt = x.second;
            solve(v, des, ans, val * wt, st);
        }
    }
    vector<double> calcEquation(vector<vector<string>> &equations,
                                vector<double> &values,
                                vector<vector<string>> &queries)
    {
        int n = equations.size();
        for (int i = 0; i < n; i++)
        {
            string u = equations[i][0];
            string v = equations[i][1];
            double wt = values[i];
            mp[u].push_back({v, wt});
            mp[v].push_back({u, 1 / wt});
        }
        vector<double> v;

        for (auto x : queries)
        {
            string src = x[0];
            string des = x[1];
            double ans = -1.0;
            double val = 1;
            if (mp.find(src) != mp.end() && mp.find(des) != mp.end())
            {
                unordered_set<string> st;
                solve(src, des, ans, val, st);
            }
            v.push_back(ans);
        }
        return v;
    }
};