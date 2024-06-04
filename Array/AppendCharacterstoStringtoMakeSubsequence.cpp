class Solution
{
public:
    int appendCharacters(string s, string t)
    {
        int it = 0;
        int cnt = 0;

        for (int i = 0; i < t.size(); i++)
        {
            it = s.find(t[i], it);
            if (it != string::npos)
            {
                it++;
                cnt++;
            }
            else
            {

                break;
            }
        }

        return t.size() - cnt;
    }
};
 