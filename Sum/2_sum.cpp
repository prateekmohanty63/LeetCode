#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/// Approach-1
/// Naive approach

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> res;

        int a = nums.size();

        for (int i = 0; i < a - 1; i++)
        {
            int sum = 0;
            int count = 1;
            for (int j = i + 1; j < a; j++)
            {
                sum = nums[i] + nums[j];
                count++;

                if (count % 2 == 0 && sum == target)
                {
                    res.push_back(i);
                    res.push_back(j);
                    break;
                }
                else if (count % 2 == 0 && sum != target)
                {
                    sum = 0;
                    count = 1;
                }
            }
        }
        return res;
    }
};

/// 2nd approach
/// Runtime: 8 ms, faster than 96.08% of C++ online submissions for Two Sum.
///Memory Usage: 10.6 MB, less than 56.07% of C++ online submissions for Two Sum.

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        int n = nums.size();
        vector<pair<int, int>> arr(n);

        for (int i = 0; i < n; ++i)
        {
            arr[i] = make_pair(nums[i], i);
        }

        sort(arr.begin(), arr.end());

        int left = 0, right = nums.size() - 1;
        int sum = 0;
        while (left < right)
        {

            sum = arr[left].first + arr[right].first;

            if (sum == target)
            {
                return {arr[left].second, arr[right].second};
            }

            else if (sum < target)
                left++;
            else
                right--;
        }

        return {};
    }
};

int main()
{

    return 0;
}