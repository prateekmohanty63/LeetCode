#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
   
   long long maxOr(vector<int>&vec)
   {
       long long res=0;
       int n=vec.size();
       for(int i=0;i<n;i++)
        {
            res|=vec[i];
        }
        return res;
   }

    long long maximumOr(vector<int>& nums, int k) {
        
        long long res=-1;
        int n=nums.size();

        vector<long long>nums1;
        for(auto it:nums)
        nums1.push_back(it);

     
        for(int i=0;i<n;i++)
        {
            long long a=nums[i];
            nums[i]=a<<k;
            
            long long r=maxOr(nums);
            res=max(res,r);
            nums[i]=a;
        }
      
     
     return res;
  }
};

int main()
{
    
    return 0;
}