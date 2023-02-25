#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

// Passed all test-cases

int maxPoints(vector<vector<int>>&points,int i,int prev,vector<vector<int>>&dp)
{
    // base case

    if(i>=points.size())return 0;

   if(dp[i][prev+1]!=-1)return dp[i][prev+1];

    int maxim=0;


    for(int j=0;j<3;j++)
    {
        if(j!=prev)
        {
            int pnt=points[i][j]+maxPoints(points,i+1,j,dp);
            maxim=max(maxim,pnt);
        }
    }

    return dp[i][prev+1]=maxim;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.

    vector<vector<int>>dp(n+1,vector<int>(4,-1));

   int res=maxPoints(points,0,-1,dp);

   return res;

}


// logic is correct but giving TLE

int maxPoints(vector<vector<int>>&points,int i,int j,int prev,int n,unordered_map<string,int>&dp)
{
    // base case

    if(i>=points.size())return 0;

    string res=to_string(i)+"*"+to_string(j)+"*"+to_string(prev);

    if(dp.find(res)!=dp.end())return dp[res];

    if(j>=points[0].size())return dp[res]=maxPoints(points,i+1,0,prev,n,dp);

    if(j!=prev)
    {
        // we have the option of doing the activity or not doing it
        
        return dp[res]=max(points[i][j]+maxPoints(points,i+1,0,j,n,dp),maxPoints(points,i,j+1,prev,n,dp));

    }
    else {
        return dp[res]=maxPoints(points,i,j+1,prev,n,dp);
    }

    

}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.

    unordered_map<string,int>dp;

    int res=maxPoints(points,0,0,-1,n,dp);

    return res;
}

int main()
{
    
    return 0;
}