#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// T(N)=O(n*n*n)
// S(n)=O(n*n)

class Solution {
public:
    int solve(vector<int>&nums,int i,int j,vector<vector<int>>&dp)
    {
        // base case
        if(i>j)return 0;
        int maxim=INT_MIN;

        if(dp[i][j]!=-1)return dp[i][j];

        for(int k=i;k<=j;k++)
        {
            int cost=nums[i-1]*nums[k]*nums[j+1]+solve(nums,i,k-1,dp)+solve(nums,k+1,j,dp);
            maxim=max(maxim,cost);
        }
        return dp[i][j]=maxim;
    }
    int maxCoins(vector<int>& nums) {
        
       
       // int n=nums.size();
        
        nums.insert(nums.begin()+0,1);
        nums.push_back(1);
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));

        int res=solve(nums,1,n-2,dp);

        return res;
    }
};


// T(N)=exponential
class Solution {
public:
    int solve(vector<int>&nums,int i,int j)
    {
        // base case
        if(i>j)return 0;
        int maxim=INT_MIN;

        for(int k=i;k<=j;k++)
        {
            int cost=nums[i-1]*nums[k]*nums[j+1]+solve(nums,i,k-1)+solve(nums,k+1,j);
            maxim=max(maxim,cost);
        }
        return maxim;
    }
    int maxCoins(vector<int>& nums) {
        
       
       // int n=nums.size();
        
        nums.insert(nums.begin()+0,1);
        nums.push_back(1);
        int n=nums.size();

        int res=solve(nums,1,n-2);

        return res;
    }
};

int main()
{
    
    return 0;
}