#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

// T(N)=O(m*m*m)
// S(n)=O(m*m)

class Solution {
public:
    int solve(int i,int j,vector<int>&cuts,vector<vector<int>>&dp)
    {
        // base case
        if(i>j)return 0;

        if(dp[i][j]!=-1)return dp[i][j];
        int minim=INT_MAX;



        for(int k=i;k<=j;k++)
        {
            int currCost=(cuts[j+1]-cuts[i-1])+solve(i,k-1,cuts,dp)+solve(k+1,j,cuts,dp);
            minim=min(minim,currCost);
        }
        return dp[i][j]=minim;
    }
    int minCost(int n, vector<int>& cuts) {

        int m=cuts.size();

        cuts.insert(cuts.begin()+0,0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(m+1,vector<int>(m+1,-1));

        int res=solve(1,m,cuts,dp);

        return res;
    }
};

// T(N)=exponential

class Solution {
public:
    int solve(int i,int j,vector<int>&cuts)
    {
        // base case
        if(i>j)return 0;
        int minim=INT_MAX;

        for(int k=i;k<j;k++)
        {
            int currCost=(cuts[j+1]-cuts[i-1])+solve(i,k-1,cuts)+solve(k+1,j,cuts);
            minim=min(minim,currCost);
        }
        return minim;
    }
    int minCost(int n, vector<int>& cuts) {

        int m=cuts.size();

        cuts.insert(cuts.begin()+0,0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());

        int res=solve(1,m,cuts);

        return res;
    }
};

int main()
{
    
    return 0;
}