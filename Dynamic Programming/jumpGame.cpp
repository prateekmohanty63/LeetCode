#include <iostream>
#include <vector>
using namespace std;

// recursive approach
// gives TLE

class Solution
{
public:
    bool isTrue(vector<int> &nums, int i)
    {

        if (i == nums.size() - 1)
            return true;

        else if (i > nums.size() - 1)
            return false;

        // recursive call

        for (int j = 1; j <= nums[i]; j++)
        {
            if (isTrue(nums, i + j))
                return true;
        }
        return false;
    }
    bool canJump(vector<int> &nums)
    {

        return isTrue(nums, 0);
    }
};

// Bottom up approach
// Runtime: 1176 ms, faster than 6.24% of C++ online submissions for Jump Game.
// Memory Usage: 51.2 MB, less than 5.96% of C++ online submissions for Jump Game.

class Solution
{
public:
    bool isTrue(vector<int> &nums, int i, vector<int> &dp)
    {

        // base case

        if (i == nums.size() - 1)
            return dp[i] = true;

        else if (i > nums.size() - 1)
            return false;

        // checking if value already computed
        if (dp[i] != -1)
        {
            return dp[i];
        }

        // recursive case
        for (int j = 1; j <= nums[i]; j++)
        {
            if (isTrue(nums, i + j, dp))
                return dp[i] = true;
        }

        return dp[i] = false;
    }
    bool canJump(vector<int> &nums)
    {

        vector<int> vec1(nums.size(), -1);

        return isTrue(nums, 0, vec1);
    }
};

int main()
{

    return 0;
}