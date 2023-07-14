#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

// DP
// T(N)=O(N*K*N^2)
// S(N)=O(N*k)

class Solution {
public:
    int solve(vector<int>&houses,int index,int k,vector<vector<int>>&dp)
    {
        // base case
        int n=houses.size();
        if(index>=n)return 0;
        if(k==0)return 0;

        if(k==1)
        {
            // we have to cover all the remining houses with 
            // the mailbox remaining 
            int median=((n-1)-index)/2;
            int mailBoxPos=houses[index+median];
            int totalCost=0;
            for(int j=index;j<n;j++)
            {
                totalCost+=abs(houses[j]-mailBoxPos);
            }
            return dp[index][k]=totalCost;
        }

        if(dp[index][k]!=-1)return dp[index][k];

        int ans=INT_MAX;

        for(int i=index;i<n;i++)  // O(n^2)
        {
             int median=(i-index)/2;
             int mailBoxPos=houses[index+median];
             
             int cost=0;
             for(int k=index;k<=i;k++)cost+=abs(houses[k]-mailBoxPos);
    
             ans=min(ans,cost+solve(houses,i+1,k-1,dp));
        }
        return dp[index][k]=ans;
    }
    int minDistance(vector<int>& houses, int k) {
        
        sort(houses.begin(),houses.end());
        int n=houses.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));

        int res=solve(houses,0,k,dp);

        return res;


    }
};

// Recursive 
class Solution {
public:
    int solve(vector<int>&houses,int index,int k)
    {
        // base case
        int n=houses.size();
        if(index>=n)return 0;
        if(k==0)return 0;

        if(k==1)
        {
            // we have to cover all the remining houses with 
            // the mailbox remaining 
            int median=((n-1)-index)/2;
            int mailBoxPos=houses[index+median];
            int totalCost=0;
            for(int j=index;j<n;j++)
            {
                totalCost+=abs(houses[j]-mailBoxPos);
            }
            return totalCost;
        }

        int ans=INT_MAX;

        for(int i=index;i<n;i++)
        {
             int median=(i-index)/2;
             int mailBoxPos=houses[index+median];
             
             int cost=0;
             for(int k=index;k<=i;k++)cost+=abs(houses[k]-mailBoxPos);
    
             ans=min(ans,cost+solve(houses,i+1,k-1));
        }
        return ans;
    }
    int minDistance(vector<int>& houses, int k) {
        
        sort(houses.begin(),houses.end());

        int res=solve(houses,0,k);

        return res;


    }
};

int main()
{
    
    return 0;
}