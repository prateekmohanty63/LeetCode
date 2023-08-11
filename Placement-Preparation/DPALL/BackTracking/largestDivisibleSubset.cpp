#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>hash(n);
        int lastIndex=0;
        int maxi=1;
        sort(nums.begin(),nums.end());

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0)
                {
                    if(dp[i]<1+dp[j])
                    {
                        dp[i]=dp[j]+1;
                        hash[i]=j;
                    }
                }
            }
            if(dp[i]>maxi)
            {
                maxi=dp[i];
                lastIndex=i;
            }
        }
        vector<int>res;
       
       for(int i=0;i<maxi;i++)
       {
           res.push_back(nums[lastIndex]);
           lastIndex=hash[lastIndex];
       }

        return res;
    }
};

int main()
{
    
    return 0;
}