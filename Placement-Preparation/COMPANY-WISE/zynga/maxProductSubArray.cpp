#include<iostream>
#include<vector>
#include<climits>
using namespace std;


class Solution {
public:
    int maxProduct(vector<int>& nums) {
    
         int maxRes=INT_MIN;

         for(auto it:nums)maxRes=max(maxRes,it);

         int n=nums.size();

         int currMin=1;
         int currMax=1;

         for(int i=0;i<n;i++)
         {
             // we reset the currMin and currMax
             if(nums[i]==0)
             {
                 currMin=1;
                 currMax=1;
                 continue;
             }

             int temp=currMax;
             currMax=max({nums[i],currMax*nums[i],currMin*nums[i]});
             currMin=min({nums[i],temp*nums[i],currMin*nums[i]});

             maxRes=max(maxRes,currMax);

         }
         
        return maxRes;
    }
};

int main()
{
    
    return 0;
}