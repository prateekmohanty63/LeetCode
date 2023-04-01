#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
   
   int targetFunc(vector<int>&nums,int target,int start,int end)
   {
       if(start<=end)
       {
           int mid=start+(end-start)/2;

           if(nums[mid]==target)return mid;

           if(target>nums[mid])
           return targetFunc(nums,target,mid+1,end);

           if(target<nums[mid])
           return targetFunc(nums,target,start,mid-1);
       }

       return -1;
   }

    int search(vector<int>& nums, int target) {
        
        int res=targetFunc(nums,target,0,nums.size()-1);

        return res;
    }
};

int main()
{
    
    return 0;
}