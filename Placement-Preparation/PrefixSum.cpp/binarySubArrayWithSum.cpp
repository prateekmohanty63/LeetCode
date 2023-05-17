#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// sliding window 
class Solution {
public:
   
   int almostSum(vector<int>&nums,int goal)
   {
       if(goal<0)return 0;
       // this function calculates all subarrays with sum less than equal to goal

       int start=0;
       int end=0;
       int n=nums.size();
       int currSum=0;
       int res=0;

       while(end<n)
       {
           currSum+=nums[end];

           while(currSum>goal)
           {
               currSum-=nums[start];
               start++;
           }
           res+=(end-start+1);
           end++;
       }
       return res;
   }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        // all subarrays with sum less than equal to goal - all subarrays with sum less than equal to goal-1

        return almostSum(nums,goal)-almostSum(nums,goal-1);
    }
};


// using hashmap
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        int n=nums.size();
        int res=0;
        
        int currSum=0;
        unordered_map<int,int>mp;

        mp[0]=1;

        for(int i=0;i<n;i++)
        {
            currSum+=nums[i];
            int numReq=currSum-goal;

            if(mp.find(numReq)!=mp.end())res+=mp[numReq];

            mp[currSum]++;
        }
        return res;
    }
};

int main()
{
    
    return 0;
}