#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    
    int maxSell(vector<int>&prices,int i,int transLeft)
    {
        // base case
        int n=prices.size();

        if(i>=n)return 0;

        if(transLeft==0)return 0;

        int maxProfit=0;

        int buyPrice=prices[i];

        for(int j=i+1;j<n;j++){
            int sellPrice=prices[j];

            maxProfit=max(maxProfit,sellPrice-buyPrice+maxSell(prices,j+1,transLeft-1));
        }
        maxProfit=max(maxProfit,maxSell(prices,i+1,transLeft));
        return maxProfit;
    }

    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();

        int res=maxSell(prices,0,2);

        return res;
    }
};

int main()
{
    
    return 0;
}