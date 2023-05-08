#include<iostream>
#include<unordered_map>
#include<vector>
#include<climits>
using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map<int,bool>mp;

        for(auto it:nums)
        {
            mp[it]=true;
        }
      
      int maximSequence=INT_MIN;

      for(int i=0;i<nums.size();i++)
      {
          if(mp.find(nums[i]-1)==mp.end())
          {
              // hence this is start of a sequence
              int k=nums[i];
              while(mp.find(k)!=mp.end())
              {
                  k++;
              }
              maximSequence=max(maximSequence,k-nums[i]);
          }
          else{
              // this is not the start of sequence 
              continue;
          }
      }

      if(maximSequence==INT_MIN)return 0;
         return maximSequence;
    }
};

int main()
{
    
    return 0;
}