class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        string s = "";
        int i = 0, m = word1.size(), n = word2.size();

        while (i < m || i < n)
        {
            if (i < m)
                s += word1[i];
            if (i < n)
                s += word2[i];
            i++;
        }

        return s;
    }
};

// class Solution
// {
// public:
//     string mergeAlternately(string word1, string word2)
//     {
//         string s = "";
//         int m = word1.size();
//         int n = word2.size();
//         int i = 0;
//         int j = 0;
//         while (i < m & j < n)
//         {
//             if (i == j)
//             {
//                 s += word1[i];
//                 i++;
//             }
//             else
//             {
//                 s += word2[j];
//                 j++;
//             }
//         }
//         while (i < m)
//         {
//             s += word1[i];
//             i++;
//         }

//         while (j < n)
//         {
//             s += word2[j];
//             j++;
//         }
//         return s;
//     }
// };