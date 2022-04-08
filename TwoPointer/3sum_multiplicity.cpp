#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1st method
// Runtime: 342 ms, faster than 47.97% of C++ online submissions for 3Sum With Multiplicity.
// Memory Usage: 10.5 MB, less than 68.51% of C++ online submissions for 3Sum With Multiplicity.

class Solution
{
public:
    int threeSumMulti(vector<int> &arr, int target)
    {

        int n = arr.size();
        sort(arr.begin(), arr.end());

        long long mod = 1e9 + 7;

        int count = 0;
        for (int i = 0; i < n - 2; i++)
        {
            int l = i + 1;
            int r = n - 1;

            int a = arr[i];
            int req = target - a;

            while (l < r)
            {

                int b = arr[l] + arr[r];

                if (b < req)
                    l++;
                else if (b > req)
                    r--;
                else
                {
                    int leftcount = 1;
                    int rightcount = 1;

                    while (l < r && arr[l] == arr[l + 1])
                    {
                        leftcount++;
                        l++;
                    }

                    while (l < r && arr[r] == arr[r - 1])
                    {
                        rightcount++;
                        r--;
                    }

                    if (l == r)
                    {
                        count = (count % mod + (leftcount % mod * (leftcount - 1) % mod) / 2) % mod; // number of ways of selecting 2 element from n elements
                    }
                    if (l != r)
                    {
                        count = (count % mod + (leftcount % mod * rightcount % mod) % mod) % mod;
                    }

                    l++;
                    r--;
                }
            }
        }
        return count;
    }
};

int main()
{

    return 0;
}