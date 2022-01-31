#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

/// 1st approach
/// Still this is O(n) time complexity in the worst case

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

/// 2nd Approach
/// Using map
/// Becasue we are iterating the vector to store in map this is also O(N) time complexity
/// Though note that find has O(log n) complexity even in the worst case

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {

        int n = nums.size();

        map<int, int> map1;

        for (int i = 0; i < n; i++)
        {
            map1[nums[i]] = i;
        }

        map<int, int>::iterator itr;

        itr = map1.find(target);

        if (itr == map1.end())
            return -1;

        return itr->second;
    }
};

/// 3rd approach
///Runtime: 3 ms, faster than 81.29% of C++ online submissions for Search in Rotated Sorted Array.
// Memory Usage: 11.2 MB, less than 28.81% of C++ online submissions for Search in Rotated Sorted Array.

class Solution
{
public:
    int BinarySearch(vector<int> &a, int l, int r, int t)
    {
        if (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (a[mid] == t)
                return mid;
            if (t < a[mid])
                return BinarySearch(a, l, mid - 1, t);
            if (t > a[mid])
                return BinarySearch(a, mid + 1, r, t);
        }
        return -1;
    }
    int search(vector<int> &nums, int target)
    {
        int s = 0, d = nums.size() - 1;

        while (s <= d)
        {
            int mid = s + (d - s) / 2;
            if (nums[mid] == target)
                return mid;

            if (nums[s] == target)
                return s;

            if (nums[d] == target)
                return d;

            if (nums[s] < nums[mid])
            {
                if (nums[s] < target && target < nums[mid])
                    return BinarySearch(nums, s, mid, target);
                else
                    s = mid + 1;
            }
            else
            {
                if (nums[mid] < target && target < nums[d])
                    return BinarySearch(nums, mid, d, target);
                else
                    d = mid - 1;
            }
        }
        return -1;
    }
};

int main()
{

    return 0;
}