#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    
   int MOD = 1e9+7;
    
    int numberOfMethods(int n,int l,int k,int target,int curr,vector<vector<int>>&dp)
    {
        
        // base case
        if (n == l && target == curr) return 1;
        
        if(n==l && target!=curr)return 0;
        
        if(dp[curr][l]!=-1)return dp[curr][l];
        
       
        long long total=0;
        
        
        for(int i=1;i<=k;i++)
        {
            
           total+=numberOfMethods(n,l+1,k,target,curr+i,dp);
        }
        
        return dp[curr][l]=total%MOD;
    }
    
    int numRollsToTarget(int n, int k, int target) {
       
        
      
        
         vector<vector<int>> dp(1001, vector<int> (n+1, -1));
        
        int l=0,curr=0;
        
        return numberOfMethods(n,l,k,target,curr,dp);
        
        
      
        
        
    }
};

int main()
{
    
    return 0;
}