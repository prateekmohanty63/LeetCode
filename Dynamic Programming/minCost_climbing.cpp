#include <iostream>
#include <vector>
using namespace std;

// 1st approach

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {

        int minCost = 0;
        int minCost1 = 0;

        int n = cost.size();

        // If I start from index 0

        minCost = cost[0];

        for (int i = 1; i < n - 1; i++)
        {
            if (cost[i] >= cost[i + 1])
            {
                minCost += cost[i + 1];
                i += 1;
            }
            else
            {
                minCost += cost[i];
                // i++;
            }
            // cout<<minCost;
        }

        // If I start from index 1

        minCost1 = cost[1];

        for (int i = 2; i < n - 1; i++)
        {
            if (cost[i] >= cost[i + 1])
            {
                minCost1 += cost[i + 1];
                i += 1;
            }
            else
            {
                minCost1 += cost[i];
                // i++;
            }
        }
        cout << minCost << " " << minCost1;
        return min(minCost, minCost1);
    }
};

int main()
{

    return 0;
}