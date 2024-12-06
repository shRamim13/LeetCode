class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> v;
        for (int x : asteroids)
        {
            while (!v.empty() && v.back() > 0 && x < 0)
            {
                if (v.back() < -x)
                {
                    v.pop_back();
                }
                else if (v.back() == -x)
                {
                    v.pop_back();
                    x = 0;
                    break;
                }
                else
                {
                    x = 0;
                    break;
                }
            }
            if (x != 0)
            {
                v.push_back(x);
            }
        }
        return v;
    }
};