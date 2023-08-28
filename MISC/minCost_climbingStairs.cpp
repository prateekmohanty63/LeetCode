#include <iostream>
#include <vector>
using namespace std;


// this is the correct approach
// all test cases passed
// Runtime: 10 ms, faster than 58.03% of C++ online submissions for Min Cost Climbing Stairs.
// Memory Usage: 13.9 MB, less than 28.79% of C++ online submissions for Min Cost Climbing Stairs.

// bottom up approach
class Solution {
public:
    
    // note here that greedy approach wont work ,we have to take the brute force
    // method (recursion)
    int minCost(vector<int>&cost,int n,int i,vector<int>&dp)
    {
        // base case
        if(i>=n)return 0;
        
        if(dp[i]!=0)return dp[i];
        
        // if we take 1 step
        int oneStep=cost[i]+minCost(cost,n,i+1,dp);
        
        // if we take 2 steps
        int twoStep=cost[i]+minCost(cost,n,i+2,dp);
        
        return dp[i]=min(oneStep,twoStep);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        //int minCost=0;
        //int cost=0;
        
        int n=cost.size();
        vector<int>dp(n,0);
        
        int i=0;
        
        return min(minCost(cost,n,i,dp),minCost(cost,n,i+1,dp));
        
        
    }
};

// 1st approach
// correct but exceding time limit

class Solution {
public:
    
    // note here that greedy approach wont work ,we have to take the brute force
    // method (recursion)
    int minCost(vector<int>&cost,int n,int i)
    {
        // base case
        if(i>=n)return 0;
        
        // if we take 1 step
        int oneStep=cost[i]+minCost(cost,n,i+1);
        
        // if we take 2 steps
        int twoStep=cost[i]+minCost(cost,n,i+2);
        
        return min(oneStep,twoStep);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        //int minCost=0;
        //int cost=0;
        
        int n=cost.size();
        
        int i=0;
        
        return min(minCost(cost,n,i),minCost(cost,n,i+1));
        
        
    }
};

int main()
{

}