class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t result = 0;

        for (int i = 31; i >= 0; --i)
        {
            uint32_t lsb = n & 1;
            uint32_t temp = lsb << i;
            result = temp | result;
            n = n >> 1;
        }

        return result;
    }
};
