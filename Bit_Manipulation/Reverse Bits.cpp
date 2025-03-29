class Solution
{
public:
    unsigned int reverseBits(unsigned int N)
    {
        unsigned int result = 0;
        while (N > 0)
        {
            result = (result << 1) | (N & 1); // Shift left and add LSB of N
            N >>= 1;                          // Remove last bit of N
        }
        return result;
    }
};