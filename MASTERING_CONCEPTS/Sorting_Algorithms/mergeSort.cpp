#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
   
   void merge(vector<int>&arr,int low,int mid,int high)
   {
       int nl=mid-low+1;
       int nr=high-mid;

       vector<int>leftSubArray(nl,0),rightSubArray(nr,0);
        
        // filling the left subarray
       for(int i=0;i<nl;i++){
           leftSubArray[i]=arr[low+i];
       }

       // filling the right subarray

       for(int i=0;i<nr;i++)
       {
           rightSubArray[i]=arr[mid+1+i];
       }

       // merging the array

       int ptr1=0,ptr2=0;
       int k=low;

       while(ptr1<nl && ptr2<nr)
       {
           if(leftSubArray[ptr1]<=rightSubArray[ptr2])
           {
                  arr[k++]=leftSubArray[ptr1++];
           }
           else{
               arr[k++]=rightSubArray[ptr2++];
           }
       }

       while(ptr1<nl)
       {
           arr[k++]=leftSubArray[ptr1++];
       }

       while(ptr2<nr)
       {
           arr[k++]=rightSubArray[ptr2++];
       }

   }

   void mergeArray(vector<int>&vec,int left,int right)
   {
       if(left<right){
       int mid=left+(right-left)/2;

       mergeArray(vec,left,mid);
       mergeArray(vec,mid+1,right);
       merge(vec,left,mid,right);
       }
   }

    vector<int> sortArray(vector<int>& nums) {
         
         mergeArray(nums,0,nums.size()-1);

         return nums;
    }
};

int main()
{
    
    return 0;
}