#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
   
   vector<int>sum;

   void findSum(vector<int>&toppingCosts,int i,int curr)
   {
       // base case
       if(i>=toppingCosts.size())
       {
           sum.push_back(curr);
           return ;
       }

       findSum(toppingCosts,i+1,curr+toppingCosts[i]);
       findSum(toppingCosts,i+1,curr+2*toppingCosts[i]);
       findSum(toppingCosts,i+1,curr);
   }

    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        
        findSum(toppingCosts,0,0);

        int minDiff=INT_MAX;
        int minRes=INT_MAX;

        int n=baseCosts.size();

        for(int i=0;i<n;i++)
        {
          

            for(int j=0;j<sum.size();j++)
            {
                int currDiff=abs(target-(baseCosts[i]+sum[j]));

                if(currDiff<minDiff)
                {
                    minDiff=currDiff;
                    minRes=(baseCosts[i]+sum[j]);
                }
                else if(currDiff==minDiff)
                {
                    minRes=min(minRes,baseCosts[i]+sum[j]);
                }
            }
        }
        return minRes;
    }
};

int main()
{
    
    return 0;
}