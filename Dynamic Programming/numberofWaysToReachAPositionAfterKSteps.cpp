#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


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