//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	ll mod=1e9+7;
	
	ll solve(int n,int prevIsOne,vector<vector<ll>>&dp)
	{
	    // base case
	    if(n<0)return 1;
	    
	    if(dp[n][prevIsOne]!=-1)return dp[n][prevIsOne];
	    
	    
	    ll ans=0;
	    
	    
	    if(prevIsOne==0)
	    {
	        // we have the option of taking current as 1 or current as 0
	        ans+=(solve(n-1,true,dp)%mod+solve(n-1,prevIsOne,dp)%mod)%mod;
	    }
	    else{
	        ans+=(solve(n-1,false,dp))%mod;
	    }
	    return dp[n][prevIsOne]=ans%mod;
	}
	ll countStrings(int n) {
	    // code here
	    
	   vector<vector<ll>>dp(n,vector<ll>(2,-1));
	    
	    ll res=solve(n-1,false,dp);
	    
	    return res;
	}
};

//{ Driver Code Starts.

int main() {
  
    return 0;
}
// } Driver Code Ends