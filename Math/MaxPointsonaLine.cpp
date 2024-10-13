class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        if (n == 1)
            return 1;

        int result = 0;

        for (int i = 0; i < n; i++)
        {

            unordered_map<double, int> mp;

            for (int j = 0; j < n; j++)
            {

                if (i == j)
                    continue;

                auto dy = points[j][1] - points[i][1];
                auto dx = points[j][0] - points[i][0];
                auto slope = atan2(dy, dx);

                mp[slope]++;
            }

            for (auto &it : mp)
            {
                result = max(result, it.second + 1);
            }
        }

        return result;
    }
};

// class Solution
// {
// public:
//     int maxPoints(vector<vector<int>> &points)
//     {
//         if (points.size() == 1)
//         {
//             return 1;
//         }
//         int result = 0;
//         for (int i = 0; i < points.size(); i++)
//         {
//             for (int j = i + 1; j < points.size(); j++)
//             {
//                 int cnt = 2;
//                 int x = points[i][0] - points[j][0];
//                 int y = points[i][1] - points[j][1];
//                 for (int k = 0; k < points.size(); k++)
//                 {
//                     if (k != i && k != j)
//                     {
//                         int x_ = points[k][0] - points[i][0];
//                         int y_ = points[k][1] - points[i][1];
//                         if (x * y_ == x_ * y)
//                         {
//                             cnt++;
//                         }
//                     }
//                 }
//                 result = max(result, cnt);
//             }
//         }
//         return result;
//     }
// };