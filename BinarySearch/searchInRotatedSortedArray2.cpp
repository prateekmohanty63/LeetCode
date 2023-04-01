#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;


// Search in Rotated sorted array-2


// Time complexity: O(logn + n)
// space complexity: O(n)

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
        
       int k=0;
       int l=0;
       int minim=INT_MAX;
       int maxim=INT_MIN;
       int n=nums.size();
       vector<int>sortedVector,sortedVector1(n,-1);
        
       // find the value by which array is rotated

       for(int i=0;i<n;i++)
       {
           if(nums[i]<minim)
           {
               minim=nums[i];
               k=i;
           }
           if(nums[i]>=maxim)
           {
               maxim=nums[i];
               l=i;
           }
       }
       cout<<k<<" "<<l<<endl;
       for(int i=k;i<n;i++)
       {
           sortedVector.push_back(nums[i]);
       }
       for(int i=0;i<k;i++)
       {
           sortedVector.push_back(nums[i]);
       } 

       int m=n;

       for(int i=l;i>=0;i--)
       {
           sortedVector1[m-1]=nums[i];
           m--;
       }
       for(int i=l+1;i<n;i++)
       {
           sortedVector1[m-1]=nums[i];
           m--;
       }


       for(auto it:sortedVector)cout<<it<<" ";
       cout<<endl;

       for(auto it:sortedVector1)cout<<it<<" ";

        bool a=isPresent(sortedVector,target,0,nums.size()-1);
        bool b=isPresent(sortedVector1,target,0,nums.size()-1);

        if(a!=false || b!=false)return true;

        return false;


    }
};

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