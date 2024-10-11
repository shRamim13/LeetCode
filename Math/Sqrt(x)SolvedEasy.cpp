class Solution
{
public:
    int mySqrt(int x)
    {
        if (x < 2)
            return x; // Handle cases for 0 and 1

        int left = 0, right = x / 2, ans = 0;

        while (left <= right)
        {
            int mid = left + (right - left) / 2; // Avoid potential overflow
            long long square =
                (long long)mid * mid; // Use long long to prevent overflow

            if (square == x)
            {
                return mid;
            }
            else if (square < x)
            {
                ans = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return ans; // Return the floor of the square root
    }
};
