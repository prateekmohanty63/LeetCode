#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maximProfit=0;

        int n=prices.size();
        int buy=prices[0];

        for(int i=0;i<n;i++)
        {
             int profit=prices[i]-buy;
             maximProfit=max(maximProfit,profit);
             if(prices[i]<buy)buy=prices[i];
        }

        return maximProfit;
    }
};

int main()
{
    
    return 0;
}