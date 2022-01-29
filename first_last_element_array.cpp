#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/// Optimum approach
/// modified binary search

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> res;
        int start = 0, end = nums.size() - 1, index = -1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target)
            {
                index = mid;
                end = mid - 1;
            }

            else if (target < nums[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        res.push_back(index);

        start = 0, end = nums.size() - 1, index = -1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target)
            {
                index = mid;
                start = mid + 1;
            }

            else if (target < nums[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        res.push_back(index);

        return res;
    }
};

// Approach-1
// Runtime: 21 ms, faster than 7.31% of C++ online submissions for Find First and Last Position of Element in Sorted Array.
// Memory Usage: 14.9 MB, less than 5.11% of C++ online submissions for Find First and Last Position of Element in Sorted Array.

class Solution
{
public:
    int binarySearch(vector<int> vec1, int l, int r, int target)
    {

        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (vec1[mid] == target)
            {
                return mid;
            }

            if (target < vec1[mid])
            {
                return binarySearch(vec1, l, mid - 1, target);
            }
            return binarySearch(vec1, mid + 1, r, target);
        }
        return -1;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {

        vector<int> res;

        int n = nums.size();

        int index = binarySearch(nums, 0, n - 1, target);
        cout << index;

        if (index == -1)
        {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        else
        {
            int temp1 = index, temp2 = index;
            vector<int> vec1;

            while (temp1 >= 0 && nums[temp1] == target)
            {
                vec1.push_back(temp1);
                temp1--;
            }

            while (temp2 < n && nums[temp2] == target)
            {
                vec1.push_back(temp2);
                temp2++;
            }
            sort(vec1.begin(), vec1.end());
            res.push_back(vec1[0]);
            res.push_back(vec1[vec1.size() - 1]);
        }
        return res;
    }
};

int main()
{

    return 0;
}