#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;

class Solution {
public:
    int solve(int startDate,int endDate,vector<int>&costs,unordered_map<int,bool>&mp,vector<int>&dp)
    {
         // base case
         if(startDate>endDate)return 0;

         // we can either take a one-day ticket , two day ticker or 3 day ticker

        int dontBuy=INT_MAX;

        if(dp[startDate]!=-1)return dp[startDate];

        int oneDay=costs[0]+solve(startDate+1,endDate,costs,mp,dp);
        int sevenDay=costs[1]+solve(startDate+7,endDate,costs,mp,dp);
        int thirtyDay=costs[2]+solve(startDate+30,endDate,costs,mp,dp);

        if(mp.find(startDate)==mp.end())
        dontBuy=solve(startDate+1,endDate,costs,mp,dp);

        return dp[startDate]=min(min(dontBuy,oneDay),min(sevenDay,thirtyDay));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int n=days.size();
        int startDate=days[0];
        int endDate=days[n-1];

        unordered_map<int,bool>travelDays;

        for(auto it:days)travelDays[it]=true;

        vector<int>dp(endDate+1,-1);
         
         int res=solve(startDate,endDate,costs,travelDays,dp);

         return res;

    }
};

int main()
{
    
    return 0;
}