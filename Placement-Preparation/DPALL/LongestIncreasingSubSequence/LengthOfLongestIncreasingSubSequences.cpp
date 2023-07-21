#include<iostream>
#include<vector>
#include<climits>

using namespace std;


class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int n=nums.size();
        int res=0;

        vector<int>dp_length(n,1);
        vector<int>dp_count(n,1);

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]<=nums[j])continue;

                if(dp_length[j]+1>dp_length[i])
                {
                    dp_length[i]=dp_length[j]+1;
                    dp_count[i]=dp_count[j];
                }
                else if(dp_length[j]+1==dp_length[i])
                {
                    dp_count[i]+=dp_count[j];
                }
            }
        }

        int maxLengthSubSeq=0;

        for(int i=0;i<n;i++)
        maxLengthSubSeq=max(maxLengthSubSeq,dp_length[i]);

        for(int i=0;i<n;i++)
        {
            if(dp_length[i]==maxLengthSubSeq)
            {
                res+=(dp_count[i]);
            }
        }
        return res;
    }
};

int main()
{
    
    return 0;
}