#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
   
   int minimCost(vector<int>&days,vector<int>&costs,int source,int target,int ptr,vector<vector<int>>&dp)
   {
       // base case

       if(source>target)return 0;

       if(dp[source][ptr]!=-1)return dp[source][ptr];

        int oneDay,sevenDay,thirtyDay;

       // 1-day ticket

        int tempPtr=ptr;

        while(tempPtr<days.size() && source+1>days[tempPtr])
        tempPtr++;
        
        if(tempPtr<days.size())
        oneDay=costs[0]+minimCost(days,costs,max(source+1,days[tempPtr]),target,tempPtr,dp);

        else oneDay=costs[0];

        // 7-day ticket

        tempPtr=ptr;
        
        
        while(tempPtr<days.size() && source+7>days[tempPtr])
        tempPtr++;
         
         if(tempPtr<days.size())
        sevenDay=costs[1]+minimCost(days,costs,max(source+7,days[tempPtr]),target,tempPtr,dp);

        else sevenDay=costs[1];

        
        // 30-day ticket

        tempPtr=ptr;

        while(tempPtr<days.size() && source+30>days[tempPtr])
        tempPtr++;
        
        if(tempPtr<days.size())
        thirtyDay=costs[2]+minimCost(days,costs,max(source+30,days[tempPtr]),target,tempPtr,dp);

        else thirtyDay=costs[2];

        return dp[source][ptr]=min(oneDay,min(sevenDay,thirtyDay));


   }
 
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        vector<vector<int>>dp(366,vector<int>(366,-1));
        int res=minimCost(days,costs,days[0],days[days.size()-1],0,dp);

        return res;
    }
};

int main()
{
    
    return 0;
}