#include<iostream>
#include<vector>
using namespace std;


class Solution{
public:
    
    int solve(string s,int i,int j,bool isTrue,vector<vector<vector<int>>>&dp)
    {
        // base case (expression is of length 0)
        if(i>j)return 0;
        
        if(i==j)
        {
            // expression is of length 1
            if(isTrue)return s[i]=='T';
            
            else return s[i]=='F';
        }
        
        
        if(dp[i][j][isTrue]!=-1)return dp[i][j][isTrue];
        
        // k-loop
        int ans=0;
        for(int k=i+1;k<=j-1;k++)
        {
            char op=s[k];
            
            int lt=solve(s,i,k-1,true,dp);
            int lf=solve(s,i,k-1,false,dp);
            int rt=solve(s,k+1,j,true,dp);
            int rf=solve(s,k+1,j,false,dp);
            
            if(op=='^')
            {
                if(isTrue)
                ans+=(lt*rf + lf*rt);
                
                else ans+=(lf*rf + rt*lt);
            }
            else if(op=='|')
            {
                if(isTrue)
                ans+=(lt*rt + lf*rt + lt*rf);
                
                else ans+=(lf*rf);
            }
            else if(op=='&')
            {
                if(isTrue)
                ans+=(lt*rt);
                
                else ans+=(lf*rf + rt*lf + rf*lt);
            }
        }
        return  dp[i][j][isTrue]=ans%1003;
    }
    int countWays(int N, string S){
        // code here
        int n=S.length();
        
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,vector<int>(2,-1)));
        
        int res=solve(S,0,N-1,true,dp);
        
        return res;
    }
};

int main()
{
    
    return 0;
}