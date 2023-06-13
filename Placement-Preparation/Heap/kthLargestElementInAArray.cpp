#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

   int partition(vector<int>&vec,int s,int e)
   {
       // choosing the pivot element

       int pivot=vec[s];

       int cnt=0;

       for(int i=s+1;i<=e;i++){
           if(vec[i]<=pivot)cnt++;
       }

       int pivotIndex=s+cnt;
       swap(vec[s],vec[pivotIndex]);

       // keep all smaler to left of pivot and all greater to right of pivot

       int i=s,j=e;

       while(i<pivotIndex && j>pivotIndex)
       {
           while(vec[i]<=pivot)i++;

           while(vec[j]>pivot)j--;

           if(i<pivotIndex && j>pivotIndex)swap(vec[i++],vec[j--]);
       }
       return pivotIndex;
   }
    
    

    int findKthLargest(vector<int>& nums, int k) {
        
        int left=0,right=nums.size()-1,ans;
        int n=nums.size();

        while(1){
            int idx=partition(nums,left,right);

            if(idx==n-k){
                ans=nums[idx];
                break;
            }
            if(idx<n-k){
                left=idx+1;
            }
            else{
                right=idx-1;
            }
        }
        return ans;
    }
};

int main()
{
    
    return 0;
}