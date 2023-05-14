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

    int n=nums.size();
    long long res=-1;

    vector<int>prefixOr(n+1),suffixOr(n+1);

    for(int i=1;i<n;i++)
    {
        prefixOr[i]=prefixOr[i-1] | nums[i-1];
        suffixOr[n-i-1]=suffixOr[n-i] | nums[n-i];
    }    
     
    long long maxRes=-1;

    for(int i=0;i<n;i++)
    {
      
        maxRes=max(maxRes,(prefixOr[i] | ((long long)nums[i]<<k)|(suffixOr[i])));
      
   }   

     return maxRes;
  }
};


// T(n)=O(N^2)

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