#include<iostream>
#include<vector>
using namespace std;


// T(n)=O(logn)
// S(n)=O(1)

class Solution {
public:
   int binSearch(vector<int>&nums)
   {
       int low=0;
       int high=nums.size()-2;
       int n=nums.size();

       while(low<=high)
       {
           int mid=low+(high-low)/2;
           
           if(mid%2==0)
           {
               if(mid+1<n && nums[mid]==nums[mid+1])
               {
                   // it is the left half
                   // we shrink the left half
                   low=mid+1;
               }
               else{
                     // it in not the left half 
                     high=mid-1;
               }
           }
           else{
                 if(mid-1>=0 && nums[mid]==nums[mid-1])
                 {
                     // it is the left half
                     // we shrink the left half
                     low=mid+1;
                 }
                 else{
                     high=mid-1;
                 }
           }
       }
       return nums[low];
   }
    int singleNonDuplicate(vector<int>& nums) {
        
        return binSearch(nums);
    }
};

int main()
{
    
    return 0;
}