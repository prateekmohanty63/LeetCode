#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

class Solution {
public:
    
    long long numberTarget(vector<int>&nums,int target,map<int,int>&umap)
    {
            long long count=0;
           
        
            int start=0,end=nums.size()-1;
        
          while(start<end)
          {
            
              int tar=nums[start]+nums[end];
              
              if(tar==target)
              {
                  if(nums[start]!=nums[end])count+=umap[nums[start]]*umap[nums[end]];
                  else {
                      long long a=umap[nums[start]];
                      count+=((a*(a-1))/2);
                  }
                  while(start+1<nums.size() && nums[start]==nums[start+1]){
                     start++;
                  }
                 
                  
                  start++;
              }
              else if(tar<target)
              {
                  start++;
              }
              else{
                  end--;
              }
          }
        return count;
    }
    
    int countPairs(vector<int>& nums) {
        
        long res=0;
        
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        map<int,int>freq;
        
        for(auto i:nums)
        {
            freq[i]++;
        }
        
        
        
       vector<int>powerOf;
        
        for(int i=0;i<=21;i++)
        {
            powerOf.push_back(pow(2,i));
        }
        
        for(int i=0;i<=21;i++)
        {
            int target=powerOf[i];
            
            res+=numberTarget(nums,target,freq);
            
            
        }
        return res%1000000007;
    }
};

int main()
{
    
    return 0;
}