#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
   
   double largestSum(vector<int>&nums,int i,int k,vector<vector<double>>&dp)
   {
       // base case
       int n=nums.size();
       if(i>=n || k<0)return 0;

     // if we have not taken all nums in our partition we return INT_MIN (invalid case)
       if(k==0)return INT_MIN;

       if(dp[i][k]!=-1)return dp[i][k];

      
       double currSum=0;
       double ans=0;
       for(int j=i;j<n;j++)
       {
          currSum+=nums[j];
          ans=max(ans,currSum/(j-i+1)+largestSum(nums,j+1,k-1,dp));
         
       }
    return dp[i][k]=ans;
      
   }

    double largestSumOfAverages(vector<int>& nums, int k) {
        
        int n=nums.size();
        double res=0;
        vector<vector<double>>dp(n+1,vector<double>(k+1,-1));

        double sum=0;

        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }

        if(k==1)return (double)sum/n;

        if(k==n)return sum;

        return largestSum(nums,0,k,dp);


    }
};

class Solution {
public:
   
   double largestSum(vector<int>&nums,int i,int k)
   {
       // base case
       int n=nums.size();
       if(i>=n || k<0)return 0;

     // if we have not taken all nums in our partition we return INT_MIN (invalid case)
       if(k==0)return INT_MIN;

      
       double currSum=0;
       double ans=0;
       for(int j=i;j<n;j++)
       {
          currSum+=nums[j];
          ans=max(ans,currSum/(j-i+1)+largestSum(nums,j+1,k-1));
         
       }
    return ans;
      
   }

    double largestSumOfAverages(vector<int>& nums, int k) {
        
        int n=nums.size();
        double res=0;

        double sum=0;

        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }

        if(k==1)return (double)sum/n;

        if(k==n)return sum;

        return largestSum(nums,0,k);


    }
};

int main()
{
    
    return 0;
}