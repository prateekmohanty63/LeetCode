#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

// 1st method
// doesnt work

class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {

        int n = nums.size();

        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }

        sort(nums.begin(), nums.end());
        if (sum < target)
            return 0;

        int count = 0;

        if (sum == target)
            count++;

        for (int i = 0; i < n; i++)
        {
            int sum1 = sum;
            for (int j = i; j < n; j++)
            {
                sum1 -= 2 * nums[j];

                if (nums[j] != 0 && sum1 == target)
                {
                    cout << nums[j] << " ";
                    count++;
                    break;
                }
            }
        }
        int noZero = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
                noZero++;
        }
        count *= pow(2, noZero);

        return count;
    }
};

// 2nd method (brute force method)

class Solution
{
public:
    int count = 0;
    void solve(vector<int> &nums, int target, int i, int sum)
    {
        if (i == nums.size())
        {
            if (i == nums.size() && sum == target)
            {
                count++;
            }
            return;
        }

        // take positive sign

        sum += nums[i];
        solve(nums, target, i + 1, sum);
        sum -= nums[i];

        // take negative sign

        sum -= nums[i];
        solve(nums, target, i + 1, sum);
        sum += nums[i];
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {

        solve(nums, target, 0, 0);

        return count;
    }
};

int main()
{

    return 0;
}