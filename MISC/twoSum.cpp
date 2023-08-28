#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
    
    return 0;
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        
        map<int,vector<int>>mp;
        
        vector<int>res;
        
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]].push_back(i);
        }
        
        sort(nums.begin(),nums.end());
        
        int start=0,end=nums.size()-1;
        
        while(start<end)
        {
            int tar=nums[start]+nums[end];
            
            if(target==tar)
            {
                auto it=mp.find(nums[start]);
                
                vector<int>vec1=it->second;
                
                res.push_back(vec1[0]);
                it->second[0]=-1;
                
                it=mp.find(nums[end]);
                vec1=it->second;
                
                if(vec1[0]==-1)res.push_back(vec1[vec1.size()-1]);
                else res.push_back(vec1[0]);
                
                return res;
                  
               
            }
            else if(tar<target)
            {
                start++;
            }
            else{
                end--;
            }
        }
        return res;
    }
};