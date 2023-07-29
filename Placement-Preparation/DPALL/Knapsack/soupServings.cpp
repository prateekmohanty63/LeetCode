#include<iostream>
#include<vector>
using namespace std;

// T(N)=O(N*N*4)
// S(N)=O(N*N)

class Solution {
public:
   vector<vector<int>>op={{100,0},{75,25},{50,50},{25,75}};

    double solve(int soupA,int soupB,vector<vector<double>>&dp)
    {
        // base case
        if(soupA<=0 && soupB<=0)return 0.5;

        if(soupA<=0)return 1.0;

        if(soupB<=0)return 0.0;

        if(dp[soupA][soupB]!=-1)return dp[soupA][soupB];

        double prob=0.0;

        for(auto it:op)
        {
            int taken_A=it[0];
            int taken_B=it[1];

            prob+=solve(max(0,soupA-taken_A),max(0,soupB-taken_B),dp);
        }
        return dp[soupA][soupB]=0.25*prob;
    }
    double soupServings(int n) {
        
        if(n>=5000)return 1.0;
        vector<vector<double>>dp(n+1,vector<double>(n+1,-1));
        double res=solve(n,n,dp);

        return res;
    }
};

int main()
{
    
    return 0;
}