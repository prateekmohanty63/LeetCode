#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;


// TLE 
// T(N)=O(n*p)
// S(N)=O(n*p)

class Solution {
public:
    int solve(vector<int>&nums,int ind,int p,vector<vector<int>>&dp)
    {
        // base case
        int n=nums.size();
        if(p==0)return 0;

        if(ind>=n-1)return INT_MAX;

        if(dp[ind][p]!=-1)return dp[ind][p];

        // we have the option to take the consecutive indices currently
        // or not take the current consecutive and move ahead

        return dp[ind][p]=min(solve(nums,ind+1,p,dp),max(nums[ind+1]-nums[ind],solve(nums,ind+2,p-1,dp)));
    }
    int minimizeMax(vector<int>& nums, int p) {
        
        // sorting the nums
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(p+1,-1));
        
        int res=solve(nums,0,p,dp);

        return res;

        
    }
};

// TLE
class Solution {
public:
    int solve(vector<int>&nums,int ind,int p)
    {
        // base case
        int n=nums.size();
        if(p==0)return 0;

        if(ind>=n-1)return INT_MAX;

        // we have the option to take the consecutive indices currently
        // or not take the current consecutive and move ahead

        return min(solve(nums,ind+1,p),max(nums[ind+1]-nums[ind],solve(nums,ind+2,p-1)));
    }
    int minimizeMax(vector<int>& nums, int p) {
        
        // sorting the nums
        sort(nums.begin(),nums.end());
        
        int res=solve(nums,0,p);

        return res;

        
    }
};

int main()
{
    
    return 0;
}