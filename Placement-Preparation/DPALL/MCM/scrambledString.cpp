#include<iostream>
#include<unordered_map>
using namespace std;


class Solution{
    public:
    
    bool solve(string s1,string s2,unordered_map<string,bool>&dp)
    {
        int n=s1.length();
        // base case
        if(s1==s2)return true;
        
        if(s1.length()<1 || s2.length()<1)return false;
        
        string res=s1+"*"+s2;
        
        if(dp.find(res)!=dp.end())return dp[res];
      
        bool ans=false;
        // k-loop
        for(int k=1;k<=n-1;k++)
        {
            // either we swap at this position 
            // or we dont swap at this position
            
            // case-1: swap
            if((solve(s1.substr(0,k),s2.substr(n-k,k),dp) && solve(s1.substr(k,n-k),s2.substr(0,n-k),dp)
              || 
             (solve(s1.substr(0,k),s2.substr(0,k),dp) && solve(s1.substr(k,n-k),s2.substr(k,n-k),dp))
             )){
            
            ans=true;
            break;
             }
            // case-2: no swap
            
            
        }
        return dp[res]=ans;
    }
    bool isScramble(string S1, string S2){
        //code here
        int n=S1.length();
        int m=S2.length();
        if(n!=m)return false;
        
        if(n==0 && m==0)return true;
        
        unordered_map<string,bool>dp;
        
        bool res=solve(S1,S2,dp);
        
        return res;
    }    
};


int main()
{
    
    return 0;
}