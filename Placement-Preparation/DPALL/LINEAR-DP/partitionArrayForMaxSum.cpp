#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int maxPossibleSum(vector<int>&arr,int k,int index,vector<int>&dp)
    {
        // base case
        int n=arr.size();
        if(index>=n)return 0;

        int maxNum=INT_MIN;
        int maxRes=INT_MIN;

        if(dp[index]!=-1)return dp[index];

        for(int i=index;i<min(n,index+k);i++)
        {
           maxNum=max(maxNum,arr[i]);
           int sum=maxNum*(i-index+1);

           maxRes=max(maxRes,sum+maxPossibleSum(arr,k,i+1,dp));
        }
        return dp[index]=maxRes;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        int n=arr.size();
        vector<int>dp(n,-1);
        int res=maxPossibleSum(arr,k,0,dp);

        return res;
    }
};

int main()
{
    
    return 0;
}