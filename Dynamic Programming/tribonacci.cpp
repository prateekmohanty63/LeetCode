#include <iostream>
#include <vector>
using namespace std;

// 1st method
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for N-th Tribonacci Number.
// Memory Usage: 6.1 MB, less than 20.21% of C++ online submissions for N-th Tribonacci Number.

class Solution
{
public:
    int tribonacci(int n)
    {

        vector<int> dp;

        dp.push_back(0);
        dp.push_back(1);
        dp.push_back(1);

        for (int i = 3; i <= n; i++)
        {
            int a = dp[i - 1] + dp[i - 2] + dp[i - 3];
            dp.push_back(a);
        }

        cout << dp[n];

        return dp[n];
    }
};

int main()
{

    return 0;
}