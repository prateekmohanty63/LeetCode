#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;


class Solution {
public:
   
   int firstOccur(vector<int>&nums,int target)
   {
       int start=0;
       int end=nums.size()-1;
       int minIndex=INT_MAX;
      

       while(start<=end)
       {
           int mid=start+(end-start)/2;

           if(nums[mid]==target)
           {
               minIndex=max(minIndex,mid);

              if(mid==0)return 0;

              else if(mid-1>=0 && nums[mid-1]!=target)return mid;

              else if(mid-1>=0 && nums[mid-1]==target)
              {
                  end=mid-1;
              }
           }
           else if(target>nums[mid])
           {
               start=mid+1;
           }
           else {
               end=mid-1;
           }
       }
       return -1;
   }

   int lastOccurance(vector<int>&nums,int target)
   {
        int start=0;
       int end=nums.size()-1;
       int maxIndex=INT_MIN;
       int n=nums.size();
      

       while(start<=end)
       {
           int mid=start+(end-start)/2;

           if(nums[mid]==target)
           {
               maxIndex=max(maxIndex,mid);
               
               if(mid==n-1)return mid;

               else if(mid+1<n && nums[mid+1]!=target)return mid;

               else if(mid+1<n && nums[mid+1]==target)
               start=mid+1;
              
           }
           else if(target>nums[mid])
           {
               start=mid+1;
           }
           else {
               end=mid-1;
           }
       }
       return -1;
   }

    vector<int> searchRange(vector<int>& nums, int target) {
        
        int minOccur=firstOccur(nums,target);

        if(minOccur==-1)return {-1,-1};

        int maxOccur=lastOccurance(nums,target);

        return {minOccur,maxOccur};
    }
};

int main()
{
    
    return 0;
}