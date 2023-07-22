#include<iostream>
#include<map>
#include<vector>
using namespace std;



class Solution {
public:
    map<vector<int>,bool>mp;
    void solve(vector<int>&nums,int l,int h)
    {
        // base case
        if(l==h)
        {
          mp[nums]=true;
           return ;
        }

        for(int i=l;i<=h;i++)
        {
            swap(nums[l],nums[i]);
            solve(nums,l+1,h);
            swap(nums[l],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        int n=nums.size();
        vector<vector<int>>res;
       
        solve(nums,0,n-1);

        for(auto it:mp)res.push_back(it.first);

        return res;
    }
};


int main()
{
    
    return 0;
}