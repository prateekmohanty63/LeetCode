#include<iostream>
#include<climits>
#include<vector>
using namespace std;


// optimized memoization

class Solution{
public:
    bool isPalindrome(string str,int i,int j)
    {
        while(i<=j)
        {
            if(str[i]!=str[j])return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(string str,int i,int j,vector<vector<int>>&dp)
    {
        // base case
        // if string is of size 0 or 1 , we dont need to do any partitions
        if(i>=j)return 0;
        
        if(isPalindrome(str,i,j))return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        
        int ans=INT_MAX;
        
        for(int k=i;k<j;k++)
        {
            int left,right;
            
            if(dp[i][k]!=-1)left=dp[i][k];
            
            else left=solve(str,i,k,dp);
            
            if(dp[k+1][j]!=-1)right=dp[k+1][j];
            
            else right=solve(str,k+1,j,dp);
            
           // here +1 refers to that we have done 1 partition
            int tempAns=1+left+right;
            ans=min(ans,tempAns);
        }
        return dp[i][j]=ans;
    }
    int palindromicPartition(string str)
    {
        // code here
        int n=str.length();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        
        int res=solve(str,0,n-1,dp);
        
        return res;
        
        
    }
};


// Time complexity: 
// each call to solve , isPalindrome is also called , which is O(N)
//  for each str of length N , there are total N-1 partitions possible = O(N*(N-1))
// T(N)=O(N^3)

class Solution{
public:
    bool isPalindrome(string str,int i,int j)
    {
        while(i<=j)
        {
            if(str[i]!=str[j])return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(string str,int i,int j)
    {
        // base case
        // if string is of size 0 or 1 , we dont need to do any partitions
        if(i>=j)return 0;
        
        if(isPalindrome(str,i,j))return 0;   // O(N)
        
        
        int ans=INT_MAX;
        

        for(int k=i;k<j;k++)   
        {
            
           // here +1 refers to that we have done 1 partition
            int tempAns=1+solve(str,i,k)+solve(str,k+1,j);
            ans=min(ans,tempAns);
        }
        return ans;
    }
    int palindromicPartition(string str)
    {
        // code here
        int n=str.length();
        
        int res=solve(str,0,n-1);
        
        return res;
        
        
    }
};

int main()
{
    
    return 0;
}