#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Time complexity: 48ms Beats 94.95%of users with C++
// Space complexity: 235.19MB Beats 16.16%of users with C++
class Solution {
public:
    bool solve(vector<int>&stones,int ind,int prevJump,unordered_map<int,int>&stonePos,vector<vector<int>>&dp)
    {
        int n=stones.size();

        if(ind==n-1)return true;

        if(ind>=n)return false;

        if(dp[ind][prevJump]!=-1)return dp[ind][prevJump];

        bool ans=false;
        int nextPos=stones[ind]+prevJump;
        if(stonePos.find(nextPos)!=stonePos.end())
        {
            int i=stonePos[nextPos];
            ans=(ans || solve(stones,i,prevJump,stonePos,dp));
        }

        nextPos=stones[ind]+prevJump-1;

        if(stonePos.find(nextPos)!=stonePos.end() && nextPos>stones[ind])
        {
            int i=stonePos[nextPos];
            ans=(ans || (solve(stones,i,prevJump-1,stonePos,dp)));
        }

        nextPos=stones[ind]+prevJump+1;

        if(stonePos.find(nextPos)!=stonePos.end())
        {
            int i=stonePos[nextPos];
            ans=(ans || solve(stones,i,prevJump+1,stonePos,dp));
        }

        return dp[ind][prevJump]=ans;
    }
    bool canCross(vector<int>& stones) {
        
        unordered_map<int,int>stonePos;
        int n=stones.size();

        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));

        for(int i=0;i<n;i++)
        stonePos[stones[i]]=i;
        
       // for(auto it:stonePos)cout<<it.first<<" "<<it.second<<endl;

       if(stonePos.find(1)==stonePos.end())return false;

        return solve(stones,1,1,stonePos,dp);

    }
};


// TLE

class Solution {
public:
    bool solve(vector<int>&stones,int ind,int prevJump,unordered_map<int,int>&stonePos)
    {
        int n=stones.size();

        if(ind==n-1)return true;

        if(ind>=n)return false;

        bool ans=false;
        int nextPos=stones[ind]+prevJump;
        if(stonePos.find(nextPos)!=stonePos.end())
        {
            int i=stonePos[nextPos];
            ans=(ans || solve(stones,i,prevJump,stonePos));
        }

        nextPos=stones[ind]+prevJump-1;

        if(stonePos.find(nextPos)!=stonePos.end() && nextPos>stones[ind])
        {
            int i=stonePos[nextPos];
            ans=(ans || (solve(stones,i,prevJump-1,stonePos)));
        }

        nextPos=stones[ind]+prevJump+1;

        if(stonePos.find(nextPos)!=stonePos.end())
        {
            int i=stonePos[nextPos];
            ans=(ans || solve(stones,i,prevJump+1,stonePos));
        }

        return ans;
    }
    bool canCross(vector<int>& stones) {
        
        unordered_map<int,int>stonePos;
        int n=stones.size();

        for(int i=0;i<n;i++)
        stonePos[stones[i]]=i;
        
       // for(auto it:stonePos)cout<<it.first<<" "<<it.second<<endl;

       if(stonePos.find(1)==stonePos.end())return false;

        return solve(stones,1,1,stonePos);

    }
};

// Memory limit exceeded

class Solution {
public:
     bool solve(vector<int>&stones,int curr,unordered_map<int,bool>&stonePos,int prevJump,vector<vector<int>>&dp)
    {
        // base case
        int n=stones.size();
        if(curr==stones[n-1])return true;

        if(curr>stones[n-1])return false;

        if(stonePos.find(curr)==stonePos.end())return false;

        if(dp[curr][prevJump]!=-1)return dp[curr][prevJump];

        if(prevJump==1)
        return dp[curr][prevJump]=solve(stones,curr+prevJump,stonePos,prevJump,dp) || solve(stones,curr+prevJump+1,stonePos,prevJump+1,dp);

else 
 return dp[curr][prevJump]=solve(stones,curr+prevJump,stonePos,prevJump,dp) || solve(stones,curr+prevJump-1,stonePos,prevJump-1,dp) || solve(stones,curr+prevJump+1,stonePos,prevJump+1,dp);
    }
    bool canCross(vector<int>& stones) {
        
        unordered_map<int,bool>stonePos;
        int n=stones.size();
        int maxPos=stones[n-1];
        vector<vector<int>>dp(maxPos+1,vector<int>(maxPos+1,-1));

        for(int i=0;i<n;i++)
        stonePos[stones[i]]=true;

        return solve(stones,1,stonePos,1,dp);
    }
};


// TLE
class Solution {
public:
     bool solve(vector<int>&stones,int curr,unordered_map<int,bool>&stonePos,int prevJump)
    {
        // base case
        int n=stones.size();
        if(curr==stones[n-1])return true;

        if(curr>stones[n-1])return false;

        if(stonePos.find(curr)==stonePos.end())return false;

        if(prevJump==1)
        return solve(stones,curr+prevJump,stonePos,prevJump) || solve(stones,curr+prevJump+1,stonePos,prevJump+1);

else 
 return solve(stones,curr+prevJump,stonePos,prevJump) || solve(stones,curr+prevJump-1,stonePos,prevJump-1) || solve(stones,curr+prevJump+1,stonePos,prevJump+1);
    }
    bool canCross(vector<int>& stones) {
        
        unordered_map<int,bool>stonePos;
        int n=stones.size();

        for(int i=0;i<n;i++)
        stonePos[stones[i]]=true;

        return solve(stones,1,stonePos,1);
    }
};

int main()
{
    
    return 0;
}