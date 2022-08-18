#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    
    int isPresent(vector<int>&nums,int target)
    {
        int start=0,end=nums.size()-1;
        int count=0;
        
        while(start<end)
        {
            int tar=nums[start]+nums[end];
            
            if(tar==target)
            {
                count++;
                start++;
                end--;
                
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
    
    int maxOperations(vector<int>& nums, int k) {
        
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        int res=isPresent(nums,k);
        
        return res;
       
    }
};

int main()
{
    
    return 0;
}