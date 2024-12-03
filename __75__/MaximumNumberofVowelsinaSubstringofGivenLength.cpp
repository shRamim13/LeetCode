class Solution
{
public:
    int maxVowels(string s, int k)
    {
        unordered_set<char> st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        int cnt = 0;
        int maxi = 0;
        for (int i = 0; i < k; i++)
        {
            if (st.find(s[i]) != st.end())
            {
                cnt++;
            }
        }
        maxi = cnt;
        for (int i = k; i < s.size(); i++)
        {
            if (st.find(s[i]) != st.end())
            {
                cnt++;
            }
            if (st.find(s[i - k]) != st.end())
            {
                cnt--;
            }
            maxi = max(cnt, maxi);
        }
        return maxi;
    }
};