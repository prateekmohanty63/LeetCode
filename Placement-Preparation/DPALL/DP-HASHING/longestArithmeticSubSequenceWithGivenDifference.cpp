#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        
        int n=arr.size();

         int ans=0;
         vector<int>dp(n+1,0);

         for(int i=0;i<n;i++)
         {
             for(int j=i+1;j<n;j++)
             {
                 int diff=arr[j]-arr[i];
                 
                 if(diff==difference){
                     dp[j]=max(2,dp[i]+1);
                     ans=max(ans,dp[j]);
                 }
             }
         }
         if(ans==0)return 1;
         return ans;
    }
};

int main()
{
    
    return 0;
}