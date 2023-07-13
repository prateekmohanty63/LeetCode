#include<iostream>
#include<vector>
using namespace std;

// T(N)==O(logn)
// S(N)=O(1)

class Solution {
public:
     int solve(vector<int>&nums,int target)
     {
         int n=nums.size();
         int start=0;
         int end=n-1;
         if(nums[0]==target)return 0;
         if(nums[n-1]==target)return n-1;

         while(start<=end)
         {
             int mid=start+(end-start)/2;

             if(nums[mid]==target)return mid;
              
              // left half is sorted
             else if(nums[start]<=nums[mid])
             {
                 if(nums[start]<=target && nums[mid]>=target)
                 end=mid-1;
                 
                 else start=mid+1;
             }
             else if(nums[mid]<=nums[end])
             {
                  // right half is sorted
                  if(nums[mid]<=target && nums[end]>=target)
                  start=mid+1;

                  else end=mid-1;
             }
        
         }
         return -1;
     }
    int search(vector<int>& nums, int target) {
        
        int res=solve(nums,target);
        return res;
    }
};

int main()
{
    
    return 0;
}