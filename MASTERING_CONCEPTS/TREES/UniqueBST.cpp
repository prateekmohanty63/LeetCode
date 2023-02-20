#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
   
   int maxPossibleTrees(int n, vector<int> &dp)
   {
       // base case
       
       if(n==0 || n==1)return 1;
     

        if(dp[n]!=-1)return dp[n];

       int ans=0;

       for(int i=1;i<=n;i++)
       {
        ans+=maxPossibleTrees(i-1,dp)*maxPossibleTrees(n-i,dp);
       }

       return dp[n]=ans;
       
   }

    int numTrees(int n) {
        
        // numTrees(4) = numTrees(0)*numTrees(4) +
        //                  numsTrees(1)*numTrees(3) +
        //                  numTrees(2)*numTrees(2)+
        //                  numTrees(3)*numTrees(1)+
        //                  numTrees(4)*numTrees(0)

        vector<int>dp(n+1,-1);

        return maxPossibleTrees(n,dp);
    }
};

int main()
{
    
    return 0;
}