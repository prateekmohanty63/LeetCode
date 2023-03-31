#include<iostream>
#include<vector>
using namespace std;


// Time complexity: O(logn)
// method: binary search

class Solution {
public:
   
   int findPeakInd(vector<int>&nums,int start,int end)
   {
       int n=nums.size();
      // if(start==end)return start;
       if(start<=end)
       {
           int mid=start+(end-start)/2;
           

           if(mid-1<0)
           {
               if(nums[mid]>nums[mid+1])return mid;

              
           }
           if(mid+1>=n)
           {
               if(nums[mid]>nums[mid-1])return mid;


           }
          else if(mid+1<n && mid-1>=0 && nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1])return mid;


        int leftInd=findPeakInd(nums,start,mid-1);
       int rightInd=findPeakInd(nums,mid+1,end);
                   
                   if(leftInd!=-1)
                   {
                    cout<<start<<" leftInd "<<end<<endl;
                   return leftInd;
                   }

                    if(rightInd!=-1){
                         cout<<start<<" rightInd "<<end<<endl;
                        return rightInd;
                    }
    

       }
       return -1;
   }

    int findPeakElement(vector<int>& nums) {
        
        int n=nums.size();

        if(n==1)return 0;
        
        int res=findPeakInd(nums,0,n-1);

        
        return res;
    }
};

// Time complexity: O(n)

// expected time complexity: O(logn)

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int n=nums.size();

        if(n==1)return 0;

        for(int i=0;i<n;i++)
        {
            if(i==0 && nums[i]>nums[i+1])return i;

            if(i==n-1 && nums[n-1]>nums[n-2])return n-1;

            else if(i>0 && i<n-1){
                if(nums[i]>nums[i-1] && nums[i]>nums[i+1])return i;
            }
            
        }
        return -1;
    }
};

int main()
{
    
    return 0;
}