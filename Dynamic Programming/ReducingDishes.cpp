#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Reducing Dishes

// DP solution 

class Solution {
public:

   int maximSatisfication(vector<int>&satisfication,int i,int time,vector<vector<int>>&dp)
   {
       // base case

       if(i>=satisfication.size())return 0;

       if(dp[i][time]!=-1)return dp[i][time];

       // we have the option of either taking the dish or not taking the dish

       return dp[i][time]=max(time*satisfication[i]+maximSatisfication(satisfication,i+1,time+1,dp),maximSatisfication(satisfication,i+1,time,dp));
   }

    int maxSatisfaction(vector<int>& satisfaction) {
        
        // sorting the dishes based on satisfaction level

        sort(satisfaction.begin(),satisfaction.end());
        int n=satisfaction.size();

        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));

        int res=maximSatisfication(satisfaction,0,1,dp);

        return res;


    }
};

int main()
{
    
    return 0;
}