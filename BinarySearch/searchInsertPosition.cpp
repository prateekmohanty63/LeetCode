#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    
    int binarySearch(vector<int>&nums,int start,int end,int target)
    {
         int mid=start+(end-start)/2;
        if(end>=start)
        {
           mid=start+(end-start)/2;

            if(nums[mid]==target)return mid;

            if(target<nums[mid])
            {
                return binarySearch(nums,start,mid-1,target);
            }

            else if(target>nums[mid])
            {
                return binarySearch(nums,mid+1,end,target);
            }

            //return mid;
        }
         return mid;
    }

    int searchInsert(vector<int>& nums, int target) {
        
        int n=nums.size();

        int start=0;
        int end=n-1;

        return binarySearch(nums,start,end,target);
    }
};

int main()
{
    
    return 0;
}