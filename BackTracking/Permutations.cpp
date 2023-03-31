#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
   
   void solve(vector<int>&nums,vector<vector<int>>&res,int ind)
   {
       // base case

       if(ind==nums.size())
       {
           res.push_back(nums);
           return ;
       }

       for(int i=ind;i<nums.size();i++)
       {
           swap(nums[i],nums[ind]);
           solve(nums,res,ind+1);
           swap(nums[i],nums[ind]);
       }
   }

    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>>res;

        solve(nums,res,0);

        return res;
    }
};

int main()
{
    
    return 0;
}