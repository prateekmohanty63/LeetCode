#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// Search in Rotated sorted array-2

// Time complexity: O(logn+nlogn)
// space complexity:O(1)

class Solution {
public:
  
   bool isPresent(vector<int>&nums,int target,int start,int end)
   {
       // base case

       if(start<=end)
       {
           int mid=start+(end-start);

           if(nums[mid]==target)return true;

           if(target>nums[mid])
           return isPresent(nums,target,mid+1,end);

           if(target<nums[mid])
           return isPresent(nums,target,start,mid-1);
       }
       return false;
   }

    bool search(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());

        return isPresent(nums,target,0,nums.size()-1);


    }
};

int main()
{
    
    return 0;
}