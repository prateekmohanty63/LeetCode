#include <iostream>
#include <vector>
using namespace std;

/// Approach-1
//Runtime: 46 ms, faster than 24.77% of C++ online submissions for Move Zeroes.
//Memory Usage: 21.2 MB, less than 5.00% of C++ online submissions for Move Zeroes.

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {

        int n = nums.size();

        vector<int> index;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
                index.push_back(i);
        }

        for (int i = 0; i < index.size(); i++)
        {
            nums.push_back(nums[index[i]]);
        }

        for (int i = 0; i < n - index.size(); i++)
        {
            nums.push_back(0);
        }
        vector<int>::iterator itr;
        vector<int>::iterator itr1;

        itr = nums.begin();
        itr1 = nums.begin() + n;

        nums.erase(itr, itr1);
    }
};

int main()
{

    return 0;
}