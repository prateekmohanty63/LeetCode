#include <iostream>
using namespace std;

/// 1st approach

class Solution
{
public:
    char findTheDifference(string s, string t)
    {

        if (s.size() == 0)
            return t[0];

        int a = 0, b = 0;

        for (int i = 0; i < s.size(); i++)
        {
            a += (int)(s[i]);
        }

        for (int i = 0; i < t.size(); i++)
        {
            b += (int)(t[i]);
        }
        int k = b - a;

        return char(k);
    }
};

int main()
{

    return 0;
}