#include <iostream>
#include<vector>
using namespace std;

//Runtime: 78 ms, faster than 5.14% of C++ online submissions for Two Sum II - Input Array Is Sorted.
//Memory Usage: 15.5 MB, less than 75.27% of C++ online submissions for Two Sum II - Input Array Is Sorted.

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {

        int start = 0, end = numbers.size() - 1;
        int sum = 0;

        vector<int> res;
        while (start < end)
        {
            sum = numbers[start] + numbers[end];
            cout << sum << " ";

            if (sum == target)
            {
                res.push_back(start + 1);
                res.push_back(end + 1);
                break;
            }
            else if (sum < target)
            {
                start++;
            }
            else if (sum > target)
            {
                end--;
            }
        }
        return res;
    }
};

int main()
{

    return 0;
}