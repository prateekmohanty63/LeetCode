#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/// 1st approach

class Solution
{
public:
    int binarySearch(vector<int> &nums, int left, int right, int target)
    {
        if (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
                return mid;

            else if (target < nums[mid])
            {
                return binarySearch(nums, left, mid - 1, target);
            }
            else
                return binarySearch(nums, mid + 1, right, target);
        }
        return -1;
    }
    int search(vector<int> &nums, int target)
    {

        vector<int> vec1;
        vec1 = nums;
        sort(vec1.begin(), vec1.end());
        int n = nums.size();
        int index = binarySearch(vec1, 0, n - 1, target);

        if (index == -1)
            return -1;

        if (vec1 == nums)
            return index;

        vector<int>::iterator itr;
        itr = find(nums.begin(), nums.end(), target);

        int offset = itr - nums.begin();

        offset = index - offset;
        cout << offset << " " << index;
        return (index - (offset)) % n;
    }
};

int main()
{

    return 0;
}