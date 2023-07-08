//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// T(N)=O(N^2)
// S(N)=O(N^2)

class Solution{
public:
    int solve(int i,int j,int arr[],vector<vector<int>>&dp)
    {
        // base case
        // only 1 matrix is present , there is no multiplication with just 1 matrix
        if(i==j)return 0;
        int minim=INT_MAX;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        for(int k=i;k<j;k++)
        {
           int steps=arr[i-1]*arr[k]*arr[j]+solve(i,k,arr,dp)+solve(k+1,j,arr,dp);   
           minim=min(minim,steps);
        }
        return dp[i][j]=minim;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>>dp(N+1,vector<int>(N+1,-1));
        
        return solve(1,N-1,arr,dp);
    }
};
