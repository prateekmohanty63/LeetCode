
#include <iostream>
#include <vector>
using namespace std;

/// 1st approach

class Solution
{
public:
    int maximumWealth(vector<vector<int>> &accounts)
    {

        int n = accounts.size();
        int m = accounts[0].size();
        int max = -1;

        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = 0; j < m; j++)
            {
                sum += accounts[i][j];
            }
            if (sum > max)
                max = sum;
        }
        return max;
    }
};

int main()
{

    return 0;
}