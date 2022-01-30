#include <iostream>
#include <vector>
using namespace std;

/// Approach-1
/// This gives TLE error
/// As this becomes kind of O(N^2)
class Solution
{
public:
    void rotateArray(vector<int> &nums)
    {
        vector<int> vec1;

        int n = nums.size();

        vec1.push_back(nums[nums.size() - 1]);

        for (int i = 0; i < n - 1; i++)
        {
            vec1.push_back(nums[i]);
        }

        nums = vec1;
    }
    void rotate(vector<int> &nums, int k)
    {

        for (int i = 0; i < k; i++)
        {
            rotateArray(nums);
        }
    }
};

/// Approach-2
/// Code passing
/// Time complexity high
// Runtime: 61 ms, faster than 13.28% of C++ online submissions for Rotate Array.
// Memory Usage: 26.7 MB, less than 5.22% of C++ online submissions for Rotate Array.

class Solution
{
public:
    void rotateArray(vector<int> &nums)
    {
        vector<int> vec1;

        int n = nums.size();

        vec1.push_back(nums[nums.size() - 1]);

        for (int i = 0; i < n - 1; i++)
        {
            vec1.push_back(nums[i]);
        }

        nums = vec1;
    }
    void rotate(vector<int> &nums, int k)
    {

        int n = nums.size();

        vector<int> vec1;

        if (n >= k)
        {
            for (int i = abs(n - k); i < n; i++)
            {
                vec1.push_back(nums[i]);
            }
            for (int i = 0; i < n - k; i++)
            {
                vec1.push_back(nums[i]);
            }
            nums = vec1;
        }
        else
        {
            for (int i = 0; i < k; i++)
            {
                rotateArray(nums);
            }
        }
    }
};

/// Approach-3
// Runtime: 57 ms, faster than 17.97% of C++ online submissions for Rotate Array.
// Memory Usage: 26.3 MB, less than 5.22% of C++ online submissions for Rotate Array.

class Solution
{
public:
    void rotateArray(vector<int> &nums)
    {

        int n = nums.size();

        nums.push_back(nums[nums.size() - 1]);

        for (int i = 0; i < n - 1; i++)
        {
            nums.push_back(nums[i]);
        }
        nums.erase(nums.begin(), nums.begin() + n);
    }
    void rotate(vector<int> &nums, int k)
    {

        int n = nums.size();

        if (k <= n)
        {
            for (int i = n - k; i < n; i++)
            {
                nums.push_back(nums[i]);
            }
            for (int i = 0; i < n - k; i++)
            {
                nums.push_back(nums[i]);
            }
            nums.erase(nums.begin(), nums.begin() + n);
        }
        else
        {
            for (int i = 0; i < k; i++)
            {
                rotateArray(nums);
            }
        }
    }
};

int main()
{

    return 0;
}