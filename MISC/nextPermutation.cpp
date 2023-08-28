#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

    return 0;
}

/// Approach-1
/// MY FIRST APPROACH (NOT PASSING ALL TEST CASES)

/// Problem explanation
/// [1,2,3]
/// In dictionary [1,2,3] can be arranged as

/// 1 2 3
/// 1 3 2
/// 2 1 3
/// 2 3 1
/// 3 1 2
/// 3 2 1

/// so any of these sequences would be given, we have to find the next situation
/// if given sequence is 3 2 1 we should print 1 2 3

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {

        vector<int> nums1 = nums;
        int n = nums.size();

        sort(nums1.begin(), nums1.end(), greater<int>());

        if (nums == nums1)
        {
            sort(nums.begin(), nums.end());
            return;
        }

        int maxEle = nums1[0];
        int flag = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == maxEle && i != 0)
            {
                int temp = nums[i - 1];
                nums[i] = temp;
                nums[i - 1] = maxEle;
                flag = 1;
            }
        }
        cout << flag;
        if (flag != 1)
        {
            int secMaxEle = nums1[1];

            for (int i = 0; i < n; i++)
            {
                if (nums[i] == secMaxEle && i != 0)
                {
                    int temp = nums[i - 1];
                    nums[i] = temp;
                    nums[i - 1] = secMaxEle;
                }
            }
        }
    }
};

/// Approach-2
