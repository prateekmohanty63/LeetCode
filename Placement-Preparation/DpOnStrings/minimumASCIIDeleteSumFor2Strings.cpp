#include<iostream>
#include<vector>
#include<climits>
#include<set>
#include<unordered_map>
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


class Solution {
public:


    int maxim=INT_MIN;

    int asciiValue(string a)
    {
        int res=0;
        for(int i=0;i<a.length();i++)res+=int(a[i]);

        return res;
    }

    int maxSubSequence(string s1, string s2,int x,int y)
    {
        // your code here
        
        vector<vector<int>>vec(x+1,vector<int>(y+1));
        
        // initilization
        
      
        
        for(int i=0;i<=x;i++)
        {
            for(int j=0;j<=y;j++)
            {
                if(i==0 || j==0)vec[i][j]=0;
                
                else if(s1[i-1]==s2[j-1])
                vec[i][j]=int(s1[i-1])+vec[i-1][j-1];
                
                else
                vec[i][j]=max(vec[i-1][j],vec[i][j-1]);
            }
        }
        return vec[x][y];
    }
    int minimumDeleteSum(string s1, string s2) {
        
        
        if(s1==s2)return 0;
        set<string>vec1;

       int n=s1.length();
       int m=s2.length();
       vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
       
        
        int a=maxSubSequence(s1,s2,n,m);
        cout<<a<<" ";

        int b=asciiValue(s1);
        int c=asciiValue(s2);


        

        return (b-a)+(c-a);

    }
};

int main()
{
    
    return 0;
}