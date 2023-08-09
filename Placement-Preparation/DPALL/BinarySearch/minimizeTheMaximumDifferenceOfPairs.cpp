#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
    int countOfDiff(vector<int>&nums,int ind,vector<int>&dp,int &diff)
    {
        // base case
        int n=nums.size();

        if(ind>=n-1)return 0;

        if(dp[ind]!=-1)return dp[ind];

        if(nums[ind+1]-nums[ind]<=diff)
        return dp[ind]=max(1+countOfDiff(nums,ind+2,dp,diff),countOfDiff(nums,ind+1,dp,diff));

        else return dp[ind]=countOfDiff(nums,ind+1,dp,diff);
    }
    int minimizeMax(vector<int>& nums, int p) {
        
       
        int n=nums.size();

        sort(nums.begin(),nums.end());
        int start=0;
        int end=nums[n-1]-nums[0];

        if(p==0)return 0;

        int ans;

        while(start<=end)
        {
            int mid=start+(end-start)/2;
            // we check if there are enough pairs with difference
            // less than or equal to this
            vector<int>dp(n,-1);
            int countOfPairs=countOfDiff(nums,0,dp,mid);

            // if there are enough pairs , this can possibily be an answer
            if(countOfPairs>=p)
            {
                ans=mid;
                // we check if the difference can be lesser
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};

int main()
{
    
    return 0;
}