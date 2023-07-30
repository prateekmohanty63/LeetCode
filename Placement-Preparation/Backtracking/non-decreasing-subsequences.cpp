#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
   vector<vector<int>>res;
   map<vector<int>,bool>mp;

    void solve(vector<int>&nums,vector<int>&vec,int prevEle,int ind)
    {
       
        int n=nums.size();

        if(vec.size()>=2 && mp.find(vec)==mp.end())
        {
            mp[vec]=true;
            
            res.push_back(vec);
        }

        if(ind>=n)return ;

         int currEle=nums[ind];

        if(currEle>=prevEle)
        {
            // we have the option of including the element or not including it
            solve(nums,vec,prevEle,ind+1);

            vec.push_back(nums[ind]);
            solve(nums,vec,nums[ind],ind+1);
            vec.pop_back();
        }
        else{
            // we dont have a option to include the current element

            solve(nums,vec,prevEle,ind+1);
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        vector<int>vec;
        solve(nums,vec,-101,0);

        return res;
    }
};

int main()
{
    
    return 0;
}