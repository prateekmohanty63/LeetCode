#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;

class Solution {
public:
    
    int solve(string s,int i,unordered_map<string,bool>&mp,vector<int>&dp)
    {
        int n=s.length();
        
        if(i>=n)return 0;
        
        if(dp[i]!=-1)return dp[i];
        
        // we have two options either we take the char in the string or we dont 
        
        int ans=INT_MAX;
        
        for(int j=0;j<n;j++)
        {
            if(j+i<=n)
            {
                string a=s.substr(i,j);
               // cout<<a<<" ";
                
                if(mp.find(a)!=mp.end())
                {
                    ans=min(ans,solve(s,i+j,mp,dp));
                     
                }
               
               
            } 
           
        }
        //cout<<endl;
         // we can also skip a character
         ans=min(ans,1+solve(s,i+1,mp,dp));
         
        return dp[i]=ans;
    }
    
    int minExtraChar(string s, vector<string>& dictionary) {
        
    
        
        unordered_map<string,bool>wordDict;
        int n=s.length();
        vector<int>dp(n,-1);
        
     
        
        for(auto it:dictionary)
        {
            wordDict[it]=true;
        }
        
           if(wordDict.find(s)!=wordDict.end())return 0;
        
        return solve(s,0,wordDict,dp);
    }
};

int main()
{
    
    return 0;
}