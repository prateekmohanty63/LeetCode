#include <iostream>
#include <vector>
using namespace std;

// Correct answer
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Summary Ranges.
// Memory Usage: 6.9 MB, less than 14.46% of C++ online submissions for Summary Ranges.

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {

        vector<string> vec1;
        int n = nums.size();
        int k = 0;
        string a = "";
        string b = "";

        if (n == 0)
            return vec1;

        if (n == 1)
        {
            vec1.push_back(to_string(nums[0]));
            return vec1;
        }

                int left = -1;
        // if(nums[1]-nums[0]!=1)vec1.push_back(to_string(nums[0]));

        for (int i = 0; i < n - 1; i++)
        {

            if (abs(nums[i + 1] == 1 + nums[i]))
            {
                left = i - k;
                k++;
            }

            else
            {

                if (k > 0)
                {
                    a += to_string(nums[left]);
                    a += "->";
                    a += to_string(nums[i]);

                    vec1.push_back(a);
                    a = "";
                }
                else
                {
                    vec1.push_back(to_string(nums[i]));
                }
                k = 0;
            }
        }
        if (nums[n - 1] != 1 + nums[n - 2])
            vec1.push_back(to_string(nums[n - 1]));
        else
        {

            b += to_string(nums[left]);
            b += "->";
            b += to_string(nums[n - 1]);
            vec1.push_back(b);
        }
        return vec1;
    }
};

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {

        int n = nums.size();
        vector<string> vec1;
        string a;
        int k = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i + 1] - nums[i] == 1)
                k++;
            else
            {
                if (k != 0)
                {
                    a += to_string(nums[i - k]);
                    a += "->";
                    a += to_string(nums[i]);
                    k = 0;
                    vec1.push_back(a);
                    a = "";
                }
                else if (k == 0)
                {
                    string b = to_string(nums[i + 1]);
                    vec1.push_back(b);
                }
            }
        }

        return vec1;
    }
};

int main()
{

    return 0;
}