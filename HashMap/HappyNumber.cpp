class Solution
{
public:
    // Helper function to calculate the sum of the squares of the digits of `n`
    int getNext(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n)
    {
        int slow = n;
        int fast = getNext(n);

        // Floyd's Cycle Detection: If there's a cycle, slow and fast will eventually meet
        while (fast != 1 && slow != fast)
        {
            slow = getNext(slow);          // Move slow pointer one step
            fast = getNext(getNext(fast)); // Move fast pointer two steps
        }

        // If fast reaches 1, it is a happy number
        return fast == 1;
    }
};
