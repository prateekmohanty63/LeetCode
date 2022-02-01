// 1st approach
#include <iostream>
#include <vector>
#define INT_MAX 999999;
using namespace std;

class Solution
{
public:
    int maximumDifference(vector<int> &nums)
    {

        int n = nums.size();

        int mini = -1;
        int maxim = INT_MAX;
        int flag = 0;

        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i + 1] > nums[i])
                flag = 1;
        }

        if (flag == 0)
            return -1;

        for (int i = 0; i < n; i++)
        {
            maxim = min(maxim, nums[i]);
            mini = max(mini, nums[i] - maxim);
        }

        cout << maxim << " " << mini;
        return mini;
    }
};

/// 2nd approach

class Solution
{
public:
    int maximumDifference(vector<int> &nums)
    {

        int n = nums.size();

        int mini = -1;
        int maxim = INT_MAX;
        int flag = 0;

        for (int i = 0; i < n; i++)
        {
            maxim = min(maxim, nums[i]);
            mini = max(mini, nums[i] - maxim);
        }

        if (mini == 0)
            return -1;
        cout << maxim << " " << mini;
        return mini;
    }
};

int main()
{

    return 0;
}
