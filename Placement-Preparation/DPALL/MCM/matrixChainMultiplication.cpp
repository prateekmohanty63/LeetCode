#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution{
public:
   int solve(int N,int arr[],int i,int j,vector<vector<int>>&dp)
   {
        // base case
        
        if(i>=j)return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int ans=INT_MAX;
        
        // partitoning into k matrices
        for(int k=i;k<j;k++)
        {
            int cost=arr[i-1]*arr[k]*arr[j];
            int tempAns=cost+solve(N,arr,i,k,dp)+solve(N,arr,k+1,j,dp);
            ans=min(ans,tempAns);
        }
        return dp[i][j]=ans;
       
   }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        
        vector<vector<int>>dp(N+1,vector<int>(N+1,-1));
        
        int ans=solve(N,arr,1,N-1,dp);
        
        return ans;
    }
};

int main()
{
    
    return 0;
}