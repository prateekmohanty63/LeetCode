#include<iostream>
using namespace std;

class Solution {
public:
    int lenOfIncArray(vector<int>&nums)
    {
        int res=0;
        int n=nums.size();
        
        int start=0;
        int end=1;
        
        while(end<n)
        {
            if(nums[end]-nums[end-1]>=0)
            {
                res=max(res,end-start+1);
            }
            else{
                start=end;
            }
                
            end++;
        }
        return res;
    }
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int>nums3(n);
        int ptr1=0;
        int ptr2=0;
        
        
        int k=0;
        
        if(nums1[ptr1]<nums2[ptr2])
        {
            nums3[k++]=nums1[ptr1];
          
        }
        else nums3[k++]=nums2[ptr2];
        
        ptr1++;
        ptr2++;
        
        
        while(ptr1<n && ptr2<n)
        {
            int prevEle=nums3[k-1];
            
            if(nums1[ptr1]>=prevEle && nums2[ptr2]<prevEle)
            {
                nums3[k++]=nums1[ptr1];
               
            }
            else if(nums2[ptr2]>=prevEle && nums1[ptr1]<prevEle)
            {
                nums3[k++]=nums2[ptr2];
                
            }
            else if(nums1[ptr1]>=prevEle && nums2[ptr2]>=prevEle)
            {
                if(nums1[ptr1]<=nums2[ptr2])
                {
                    nums3[k++]=nums1[ptr1];
                }
                else{
                    nums3[k++]=nums2[ptr2];
                }
            }
            else{
                nums3[k++]=min(nums2[ptr2],nums1[ptr1]);
            }
            ptr1++;
            ptr2++;
        }
        
        for(auto it:nums3)cout<<it<<" ";
        cout<<endl;
        
        int res=lenOfIncArray(nums3);
        if(res==0)return 1;
        
        return res;
    }
};

int main()
{
    
    return 0;
}