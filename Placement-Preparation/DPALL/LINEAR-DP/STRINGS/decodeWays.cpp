#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
   
   int noMapping(string s,int i,vector<int>&dp)
   {
       // base case
       if(i==s.length())return 1;

       if(s[i]=='0')return 0;

       if(i==s.length()-1)return 1;

       if(dp[i]!=-1)return dp[i];

       string str=s.substr(i,2);

       int op1=noMapping(s,i+1,dp);
       int op2=(stoi(str)>=1 && stoi(str)<=26)?noMapping(s,i+2,dp):0;

       return dp[i]=op1+op2;
   }

    int numDecodings(string s) {
        
        int n=s.length();

         vector<int>dp(n+1,-1);
        
        return noMapping(s,0,dp);
        

    }
};

int main()
{
    
    return 0;
}