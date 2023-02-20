#include<iostream>
#include<unordered_map>
#include<climits>
using namespace std;



class Solution {
public:
   int maxOp(string s,string t,int i,int j,unordered_map<string,int>&dp)
     {
         // base case
         
         if(s==t)return 0;
         
         if(i==s.length())return t.length()-j;
         
         if(j==t.length())return s.length()-i;
         
         
         string res=to_string(i)+"*"+to_string(j);
         
         if(dp.find(res)!=dp.end())return dp[res];
         
         int ans=INT_MAX;
         
         if(s[i]==t[j])
         {
             return dp[res]=maxOp(s,t,i+1,j+1,dp);
         }
         else{
             // we have three options here 
             // 1. insert , delete or replace
             
             // insert case
             int a=1+maxOp(s,t,i,j+1,dp);
             
             // delete case
             
             int b=1+maxOp(s,t,i+1,j,dp);
             
             // replace case
             
             int c=1+maxOp(s,t,i+1,j+1,dp);
             
             ans=min(a,min(b,c));
             
         }
         
         return dp[res]=ans;
     }

    int minDistance(string s, string t) {
        

        if(s==t)return 0;
        
        if(s!=" " && t==" ")return s.length();
        
        if(s==" " && t!=" ")return t.length();
        
        unordered_map<string,int>mp;
        
        int res=0;
        
        
        int n=s.length();
        int m=t.length();
        
     
        res=maxOp(s,t,0,0,mp);
        
        return res;
    }
};

int main()
{
    
    return 0;
}