// 1st approach
#include <iostream>
#include <vector>
using namespace std;

/// DYNAMIC PROGRAMMING
/// Optimized solution
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for House Robber.
// Memory Usage: 7.9 MB, less than 24.66% of C++ online submissions for House Robber.

class Solution
{
public:
    int rob(vector<int> &nums)
    {

        int n = nums.size();

        if (n == 1)
            return nums[0];

        if (n == 2)
            return max(nums[0], nums[1]);

        int *dp = new int[n];

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++)
        {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }
        return dp[n - 1];
    }
};

/// 1st approach
/// giving wrong answer

class Solution
{
public:
    int rob(vector<int> &nums)
    {

        int n = nums.size();

        if (n == 1)
            return nums[0];

        if (n == 2)
            return max(nums[0], nums[1]);

        if (n % 2 == 0)
        {
            nums.push_back(-1);
        }

        int maxMoney = nums[0];
        int maxMoney1 = nums[1];

        for (int i = 2; i < n; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                maxMoney += nums[i];
                cout << nums[i] << endl;
                i++;
            }
            else
            {
                maxMoney += nums[i + 1];
                cout << nums[i + 1] << endl;
                i++;
            }
        }
        for (int i = 3; i < n; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                maxMoney1 += nums[i];
                cout << nums[i] << endl;
                i++;
            }
            else
            {
                maxMoney1 += nums[i + 1];
                cout << nums[i + 1] << endl;
                i++;
            }
        }
        return max(maxMoney, maxMoney1);
    }
};

/// 2nd approach
/// wrong answer

int main()
{

    return 0;
}