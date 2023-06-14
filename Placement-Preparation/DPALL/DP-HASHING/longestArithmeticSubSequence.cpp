#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// T(N)=O(N^2)
// S(N)=O(n^2)

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

// T(N)=O(N^3)

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        
        int n=nums.size();
        int maxRes=INT_MIN;

        // starting from last
        for(int i=n-1;i>0;i--)
        {

            for(int j=i-1;j>0;j--)
            {
                int currDiff=nums[i]-nums[j];
                int prevNum=nums[j];
                int count=1;

                for(int k=j-1;k>=0;k--){
                    if(prevNum-nums[k]==currDiff){
                        prevNum=nums[k];
                        count++;
                    }
                }
                maxRes=max(maxRes,count+1);
            }
        }
        return maxRes;
    }
};

int main()
{
    
    return 0;
}