#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int solve(vector<int>&nums,int start,int end,int op)
    {
        if(op==0)return nums[end]-nums[start];

        // now in each step , we have the option of 
        // either removing the element from start or end

        return min(solve(nums,start+1,end,op-1),solve(nums,start,end-1,op-1));
    }
    int minDifference(vector<int>& nums) {
        
        int n=nums.size();
        if(n<=4)return 0;
        
        sort(nums.begin(),nums.end());

        int res=solve(nums,0,n-1,3);

        return res;



    }
};

int main()
{
    
    return 0;
}