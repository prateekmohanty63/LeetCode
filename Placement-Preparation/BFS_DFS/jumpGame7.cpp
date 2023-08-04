#include<iostream>
#include<vector>
using namespace std;


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