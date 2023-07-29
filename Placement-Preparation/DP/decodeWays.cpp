#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int solve(string &s,int ind,vector<int>&dp)
    {
        int n=s.length();
        if(ind>=n)return 1;

        if(s[ind]=='0')return 0;

        if(ind==n-1)return 1;
        if(dp[ind]!=-1)return dp[ind];

        // we have the option of either taking single digit
        // which forms a alphabet with size 1 (a,b,c,d,e,f,g,h,i)
        int op1=solve(s,ind+1,dp);

        // we can also taken string of length 2 (forming theh remaining elements)
        string substr=s.substr(ind,2);
        int op2;

        if(stoi(substr)>=1 && stoi(substr)<=26)
        op2=solve(s,ind+2,dp);

        else op2=0;

        return dp[ind]=op1+op2;
    }
    int numDecodings(string s) {
        int n=s.length();
        vector<int>dp(n+1,-1);
        int res=solve(s,0,dp);

        return res;
    }
};

int main()
{
    
    return 0;
}