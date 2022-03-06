#include <iostream>
using namespace std;

// MEMOIZATION
class Solution
{
public:
    int longestSubsequence(string a, string b, int n, int m)
    {

        int dp[n + 1][m + 1];

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;

                else if (a[i - 1] == b[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];

                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }
    int longestCommonSubsequence(string text1, string text2)
    {

        int n = text1.length();
        int m = text2.length();

        return longestSubsequence(text1, text2, n, m);
    }
};

// 1st method
// Gives TLE

class Solution
{
public:
    int longestCommon(string a, string b, int n, int m)
    {

        if (n == 0 || m == 0)
            return 0;

        if (a[n - 1] == b[m - 1])
            return 1 + longestCommon(a, b, n - 1, m - 1);

        return max(longestCommon(a, b, n - 1, m), longestCommon(a, b, n, m - 1));
    }
    int longestCommonSubsequence(string text1, string text2)
    {

        int n = text1.length();
        int m = text2.length();

        return longestCommon(text1, text2, n, m);
    }
};

int main()
{

    return 0;
}