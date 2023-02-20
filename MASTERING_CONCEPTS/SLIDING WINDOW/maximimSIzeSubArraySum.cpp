#include<iostream>
#include<vector>
#include<climits>
using namespace std;


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n=nums.size();
        int sum=0;

        for(int i=0;i<n;i++)
        {
            if(nums[i]>=target)return 1;
            sum+=nums[i];
        }

        if(sum<target)return 0;

        int minLen=INT_MAX;

        int start=0;
        int end=1;

        sum=0;
        int k=0;

      
      for(int i=0;i<n;i++)
      {
         sum+=nums[i];

         while(sum>=target)
         {
             minLen=min(minLen,i-k+1);
             sum-=nums[k++];
         }
      }

     return minLen;
}
};

int main()
{
    
    return 0;
}