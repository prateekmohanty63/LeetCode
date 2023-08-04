#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// T(N)= Beats 81.35%of users with C++
// S(N)= Beats 50.35%of users with C++

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        
        int n=s.length();

        if(s[n-1]=='1')return false;

        int i=0;
        queue<int>q;
        q.push(0);
        int curr_max=0;

        while(!q.empty())
        {
            i=q.front();
            q.pop();

            if(i==n-1)return true;

            for(int j=max(i+minJump,curr_max);j<=min(i+maxJump,n-1);j++)
            {
                if(s[j]=='0')q.push(j);
            }
            curr_max=min(i+maxJump+1,n);
        }
        return false;
    }
};


// TLE 
// T(N)=O(N^2)
// S(N)=O(N)


class Solution {
public:
   
   bool reach(string &s,int &minJump,int &maxJump,int i,vector<int>&dp)
   {
       // base case
       int n=s.length();

       if(i==n-1)return true;

       if(i>=n)return false;

       if(dp[i]!=-1)return dp[i];

       bool ans=false;

       for(int j=i+1;j<n;j++)
       {
            if(s[j]=='0')
            {
                int start=i+minJump;
                int end=min(i+maxJump,n-1);

                if(start<=j && j<=end)
                {
                    ans|=reach(s,minJump,maxJump,j,dp);
                }
            }
       }
       return dp[i]=ans;

   }

    bool canReach(string s, int minJump, int maxJump) {
        
        int n=s.length();

        if(s[n-1]=='1')return false;

        vector<int>dp(n+1,-1);

        return reach(s,minJump,maxJump,0,dp);
    }
};

int main()
{
    
    return 0;
}