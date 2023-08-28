#include <iostream>
#include <vector>
#define INT_MAX 9999999;
using namespace std;

/// approach-1

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int mini = INT_MAX;
        int profit = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            mini = min(mini, prices[i]);
            profit = max(profit, (prices[i] - mini));
        }
        return profit;
    }
};

int main()
{

    return 0;
}