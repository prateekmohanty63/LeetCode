#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(1001,0));
        int ans=0;

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int diff=nums[j]-nums[i]+500;

                dp[j][diff]=max(2,dp[i][diff]+1);
                ans=max(ans,dp[j][diff]);

            }
        }
        return ans;
    }
};

int main()
{
    
    return 0;
}