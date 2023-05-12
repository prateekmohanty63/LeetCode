#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
  
  int binSearch(vector<int>&nums,int target)
  {
      int start=0;
      int end=nums.size()-1;

      while(start<=end)
      {
          int mid=start+(end-start)/2;

          if(nums[mid]==target)return mid;

          if(nums[mid]>=nums[start])
          {
              // left array is sorted
              if(target>=nums[start] && target<=nums[mid])
              {
                  end=mid-1;
              }
              else{
                  start=mid+1;
              }
          }
          else{
              // right array is sorted
              if(target<=nums[end] && target>=nums[mid])
              {
                  start=mid+1;
              }
              else{
                  end=mid-1;
              }
          }
      }
      return -1;
  }

    int search(vector<int>& nums, int target) {
        
        return binSearch(nums,target);
    }
};

int main()
{
    
    return 0;
}