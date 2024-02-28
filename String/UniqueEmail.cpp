class Solution
{
public:
    int numUniqueEmails(vector<string> &emails)
    {
        unordered_set<string> st;
        for (auto email : emails)
        {
            string s = "";
            for (auto ch : email)
            {
                if (ch == '@' || ch == '+')
                {
                    break;
                }
                if (ch == '.')
                {
                    continue;
                }
                s += ch;
            }
            s += email.substr(email.find('@'));
            st.insert(s);
        }
        return st.size();
    }
};
