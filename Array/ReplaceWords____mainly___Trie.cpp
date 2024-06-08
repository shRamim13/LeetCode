class Solution
{
public:
    string replaceWords(vector<string> &dict, string sentence)
    {

        set<string> st(dict.begin(), dict.end());
        istringstream stream(sentence);
        vector<string> str;
        string t, ans;

        while (stream >> t)
        {
            str.push_back(t);
        }

        for (string ssd : str)
        {
            int i = 1;
            while (i <= ssd.size())
            {
                string hlpr = ssd.substr(0, i);
                if (st.find(hlpr) != st.end())
                {
                    ans += hlpr + " ";
                    break;
                }
                i++;
            }

            if (i > ssd.size())
            {
                ans += ssd + " ";
            }
        }
        ans.erase(ans.size() - 1);
        return ans;
    }
};
