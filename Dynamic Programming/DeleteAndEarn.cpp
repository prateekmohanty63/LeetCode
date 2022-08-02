#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxEarn(vector<int> &nums, int i, unordered_map<int, int> &freq, vector<int> &dp)
    {

        // base case
        if (i >= nums.size())
            return 0;

        // memoization

        if (dp[i] != -1)
            return dp[i];

        int currentSum = 0;
        int currentVal = nums[i];
        int index = i + 1;

        currentSum += nums[i] * freq[nums[i]];

        while (index < nums.size() && (nums[index] == currentVal || nums[index] == currentVal + 1))
        {
            index++;
        }

        // recursion

        // we have the option of choosing the element or not choosing it

        return dp[i] = max(currentSum + maxEarn(nums, index, freq, dp), maxEarn(nums, i + 1, freq, dp));
    }

    int deleteAndEarn(vector<int> &nums)
    {

        int i = 0;

        unordered_map<int, int> freq;
        vector<int> dp(nums.size(), -1);

        for (int i = 0; i < nums.size(); i++)
            freq[nums[i]]++;

        sort(nums.begin(), nums.end());

        return maxEarn(nums, i, freq, dp);
    }
};

int main()
{

    return 0;
}