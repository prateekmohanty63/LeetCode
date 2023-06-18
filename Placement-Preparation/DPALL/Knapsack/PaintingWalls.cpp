#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int solve(vector<int>&cost,vector<int>&time,int index,int wallRem,vector<vector<int>>&dp)
    {
       // base case
       int n=cost.size();

       if(wallRem<=0)return 0;

       if(index>=n)return 2000000000;

       if(dp[index][wallRem]!=-1)return dp[index][wallRem];

       int paintIt=cost[index]+solve(cost,time,index+1,wallRem-(1+time[index]),dp);
       int dontPaint=solve(cost,time,index+1,wallRem,dp);
       
      return dp[index][wallRem]=min(paintIt,dontPaint);

    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        
        int n=time.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int res=solve(cost,time,0,n,dp);

        return res;
    }
};

int main()
{
    
    return 0;
}