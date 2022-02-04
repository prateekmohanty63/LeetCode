#include <iostream>
#include <vector>
using namespace std;

/// 1st approach
/// TLE

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {

        int n = nums.size();
        int maxim = -1;
        int sum = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] == 0)
                sum = -1;
            else
                sum = 1;
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] == 0)
                    sum--;
                else if (nums[j] == 1)
                    sum++;

                if (sum == 0)
                {
                    if (j - i + 1 > maxim)
                        maxim = j - i + 1;
                }
            }
        }
        if (maxim == -1)
            return 0;
        return maxim;
    }
};

int main()
{

    return 0;
}