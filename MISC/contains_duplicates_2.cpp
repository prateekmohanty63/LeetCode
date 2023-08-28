#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

/// Approach-1

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {

        map<int, int> map1;

        int n = nums.size();

        if (n == 1)
            return false;

        for (int i = 0; i < n; i++)
        {
            map1[nums[i]]++;
        }

        map<int, int>::iterator itr;

        for (itr = map1.begin(); itr != map1.end(); itr++)
        {

            if (itr->second >= 2)
            {
                vector<int> vec1;
                for (int i = 0; i < n; i++)
                {
                    if (nums[i] == itr->first)
                    {
                        vec1.push_back(i);
                    }
                }
                sort(vec1.begin(), vec1.end());
                int min = 9999999;
                for (int i = 0; i < vec1.size() - 1; i++)
                {
                    if (abs(vec1[i] - vec1[i + 1]) < min)
                        min = abs(vec1[i] - vec1[i + 1]);
                }
                if (min <= k)
                    return true;
            }
        }
        return false;
    }
};
int main()
{

    return 0;
}