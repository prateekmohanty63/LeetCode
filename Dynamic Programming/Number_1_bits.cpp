#include <iostream>
#include <math.h>
using namespace std;

// 1st approach
/// using recursion
/// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of 1 Bits.
// Memory Usage: 6 MB, less than 48.20% of C++ online submissions for Number of 1 Bits.

class Solution
{

    int BitCount(uint32_t n)
    {
        if (n == 0 || n == 1)
            return n;

        if (ceil(log2(n)) == floor(log2(n)))
            return 1;

        if (n & 1 == 1)
        {
            return 1 + hammingWeight(n >> 1);
        }

        else
        {
            return hammingWeight(n >> 1);
        }
    }

public:
    int hammingWeight(uint32_t n)
    {

        int count = BitCount(n);
        return count;
    }
};

// 2nd approach
class Solution
{
public:
    int count = 0;
    int hammingWeight(uint32_t n)
    {

        if (n == 0)
            return 0;
        if (n == 1)
            return 1;

        //   uint32_t a=n&1;
        //         uint32_t b=n-n&(n-1);

        if (ceil(log2(n)) == floor(log2(n)))
            return 1;

        else if (n & 1 == 1)
        {
            count += hammingWeight(n - 1) + 1;
        }
        else
        {
            count += (hammingWeight(n & (n - 1)) + hammingWeight(n - n & (n - 1)));
        }
        return count;
    }
};

int main()
{

    return 0;
}