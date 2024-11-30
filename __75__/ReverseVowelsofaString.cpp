class Solution
{
public:
    string reverseVowels(string s)
    {
        int n = s.size();
        int i = 0;
        int j = n - 1;
        unordered_map<char, int> mp;
        mp['a'] = 1;
        mp['e'] = 1;
        mp['i'] = 1;
        mp['o'] = 1;
        mp['u'] = 1;
        mp['A'] = 1;
        mp['E'] = 1;
        mp['I'] = 1;
        mp['O'] = 1;
        mp['U'] = 1;

        while (i < j)
        {
            if (mp[s[i]] != 1)
            {
                i++;
            }
            else if (mp[s[j]] != 1)
            {
                j--;
            }
            else
            {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};

class Solution
{
public:
    string reverseVowels(string s)
    {
        stack<char> stk;
        unordered_set<char> st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        st.insert('A');
        st.insert('E');
        st.insert('I');
        st.insert('O');
        st.insert('U');
        for (int i = 0; i < s.size(); i++)
        {
            if (st.find(s[i]) != st.end())
            {
                stk.push(s[i]);
            }
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (st.find(s[i]) != st.end())
            {
                s[i] = stk.top();
                stk.pop();
            }
        }
        return s;
    }
};