#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;


// Runtime: 253 ms, faster than 50.00% of C++ online submissions for Number of Ways to Reach a Position After Exactly k Steps.
// Memory Usage: 33.3 MB, less than 50.00% of C++ online submissions for Number of Ways to Reach a Position After Exactly k Steps.

class Solution {
public:

int mod = 1e9 + 7;
long dp[3100][1001];

long helper(int start , int end , int k){
    if(start==end){
       if(k==0) return 1;
    }
    if(k==0) return 0;

    
    // plus 1000 is done so that the index can stay non-negative
    // because max we can go 1000 steps back (negative)
    if(dp[start+1000][k]!=-1) return dp[start+1000][k];


    long ans = helper(start+1,end,k-1);

  
    if((k-1) >= (end-start+1)){
        ans += helper(start-1,end,k-1);
    }
    return dp[start+1000][k]=ans%mod;
}
int numberOfWays(int sp, int ep, int k) {
    memset(dp,-1,sizeof(dp));
    if(abs(sp-ep)>k) return 0;
    
    // helper
    long ans = helper(sp,ep,k);
    return ans%mod;
}
};


// 27/35 test-cases
// TLE

class Solution {
public:
    
    const unsigned int M=1000000007;
    int number(int startPos,int endPos,int k,unordered_map<string,int>&dp)
    {
        // base case
        
        if(startPos==endPos && k==0)return 1;
        
        if(k==0)return 0;
        
        
        string res=to_string(startPos)+"*"+to_string(k);
        
         if(dp.find(res)!=dp.end())return dp[res];
        
        return dp[res]=(number(startPos+1,endPos,k-1,dp)%M+number(startPos-1,endPos,k-1,dp)%M)%M;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        
        unordered_map<string,int>dp;
        return number(startPos,endPos,k,dp)%M;
    }
};

int main()
{
    
    return 0;
}