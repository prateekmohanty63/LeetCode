// 1st approach
#include <iostream>
#include <vector>
using namespace std;

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

int main()
{

    return 0;
}