#include <iostream>
#include <vector>
using namespace std;

// First approach
// Dynamic programming
/// Optimized solution
class Solution
{
public:
    int robber(vector<int> &nums)
    {

        int dp[nums.size() + 1];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++)
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        return dp[nums.size() - 1];
    }

    int rob(vector<int> &nums)
    {

        int n = nums.size();

        if (n == 1)
            return nums[0];

        if (n == 2)
            return max(nums[0], nums[1]);

        // if start from 0 index do not consider last index
        vector<int> vec1(nums.begin(), nums.end() - 1);

        // if start from index1 consider the last index
        vector<int> vec2(nums.begin() + 1, nums.end());

        // rest problem behaves as a straight line

        return max(robber(vec1), robber(vec2));
    }
};

int main()
{

    return 0;
}