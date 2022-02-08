#include <iostream>
using namespace std;

/// 1 st approach
// Runtime: 2 ms, faster than 54.83% of C++ online submissions for Add Digits.
// Memory Usage: 6 MB, less than 25.37% of C++ online submissions for Add Digits.
class Solution
{
public:
    int addDigits(int num)
    {

        string a = to_string(num);

        if (a.size() == 1)
            return num;

        while (1)
        {
            int val = 0;
            int temp = num;

            while (temp)
            {
                int b = temp % 10;
                val += b;
                temp = temp / 10;
            }

            string c = to_string(val);
            if (c.size() == 1)
                return val;

            num = val;
        }
    }
};

int main()
{

    return 0;
}