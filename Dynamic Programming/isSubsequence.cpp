#include <iostream>
using namespace std;

/// 1st approach
// Runtime: 5 ms, faster than 28.38% of C++ online submissions for Is Subsequence.
// Memory Usage: 6.4 MB, less than 72.68% of C++ online submissions for Is Subsequence.

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {

        int a = s.length();
        int b = t.length();
        int j = 0;

        for (int i = 0; i < b && j < a; i++)
        {
            if (s[j] == t[i])
                j++;
        }
        return (j == a);
    }
};

int main()
{

    return 0;
}