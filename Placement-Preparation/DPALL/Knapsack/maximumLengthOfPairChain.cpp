#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

class Solution {
public:
	int f(int i,int prev,vector<vector<int>>& pairs,int n,vector<vector<int>>& dp){

		if(i==n) return 0;

		if(dp[i][prev+1]!=-1) return dp[i][prev+1];

		// classic knapsack question
		// we can either make the pair part of the chain or leave it
		int pick=INT_MIN;

		if(prev==-1 || pairs[prev][1]<pairs[i][0])pick=1+f(i+1,i,pairs,n,dp);

		int notpick=f(i+1,prev,pairs,n,dp);
		
		return dp[i][prev+1]=max(pick,notpick);
	}

	int findLongestChain(vector<vector<int>>& pairs) {
		int n=pairs.size();
		sort(pairs.begin(),pairs.end());
		vector<vector<int>> dp(n,vector<int>(n+1,-1));
		return f(0,-1,pairs,n,dp);
	}
};

int main()
{
    
    return 0;
}