#include<iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();

        int maxProfit=0;
        int buyPrice=INT_MAX;

        for(int i=0;i<n;i++)
        {
            int buyPrice=min(buyPrice,prices[i]);

            maxProfit=max(maxProfit,prices[i]-buyPrice);
        }

        return maxProfit;
    }
};

int main()
{
    
    return 0;
}