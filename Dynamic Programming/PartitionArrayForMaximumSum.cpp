#include<iostream>
#include<vector>
#include<climits>
using namespace std;


// Passed all test-cases 

class Solution {
public:
   
   int maxSumPossible(vector<int>&arr,int i,int k,vector<int>&dp)
   {
       // base case

       if(i>=arr.size())return 0;

       int n=arr.size();

       int maxim=INT_MIN;

       int maxRes=INT_MIN;

       if(dp[i]!=-1)return dp[i];

        for(int j=i;j<min(n,i+k);j++)
        {
             maxim=max(maxim,arr[j]);

             int sum=(j-i+1)*maxim;

             maxRes=max(maxRes,sum+maxSumPossible(arr,j+1,k,dp));
        }
        return dp[i]=maxRes;
   }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {

        int n=arr.size();
        vector<int>dp(n+1,-1);
        int res=maxSumPossible(arr,0,k,dp);

        return res;
    }
};


// solutiong giveing TLE (need to convert to dp)
class Solution {
public:
   
   int maxSumPossible(vector<int>&arr,int i,int k)
   {
       // base case

       if(i>=arr.size())return 0;

       int n=arr.size();

       int maxim=INT_MIN;

       int maxRes=INT_MIN;

        for(int j=i;j<min(n,i+k);j++)
        {
             maxim=max(maxim,arr[j]);

             int sum=(j-i+1)*maxim;

             maxRes=max(maxRes,sum+maxSumPossible(arr,j+1,k));
        }
        return maxRes;
   }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        int res=maxSumPossible(arr,0,k);

        return res;
    }
};

int main()
{
    
    return 0;
}