#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int start=0;
        int end=0;
        int currSum=0;
        int n=nums.size();
        int res=INT_MAX;

        for(int i=0;i<n;i++)
        {
            if(nums[i]>=target)return 1;
        }


        while(end<n)
        {
            currSum+=nums[end];
            
            if(currSum>=target)
            {
                while(start<end && currSum>=target)
                {
                    currSum-=nums[start];
                    start++;
                }
                res=min(res,end-start+2);

            }

            end++;
        }
        if(res==INT_MAX)return 0;
        return res;
    }
};

int main()
{
    
    return 0;
}