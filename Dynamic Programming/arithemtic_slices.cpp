#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 1st approach
// Runtime: 4 ms, faster than 49.49% of C++ online submissions for Arithmetic Slices.
// Memory Usage: 7.3 MB, less than 88.02% of C++ online submissions for Arithmetic Slices.

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {

        int n = nums.size();

        if (n < 3)
            return 0;

        int count = 0;

        for (int i = 0; i < n - 1; i++)
        {

            int j = i;
            int k = j + 1;
            int c = 1;

            int d = (nums[k] - nums[j]);

            while (k < n)
            {
                if (nums[k] - nums[j] == d)
                {
                    c++;
                    k++;
                    j++;

                    if (c >= 3)
                        count++;
                }
                else
                    break;
            }
        }

        return count;
    }
};

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {

        int n = nums.size();

        if (n < 3)
            return 0;

        int count = 0;

        for (int i = 0; i < n; i++)
        {
            int k = 0;
            for (int j = i; j < n - 2; j++)
            {
                if ((nums[j] + nums[j + 2]) / 2 == nums[j + 1])
                {
                    cout << nums[j] << " " << nums[j + 1] << " " << nums[j + 2] << endl;
                    k += 3;
                    // cout<<k<<endl;
                }
                if (k >= 3)
                {
                    count++;
                    k = 0;
                }
            }
        }

        return count;
    }
};