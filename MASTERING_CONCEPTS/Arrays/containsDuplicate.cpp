#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_map<int,bool>mp;

        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            if(mp.find(nums[i])!=mp.end())return true;

            mp[nums[i]]=true;
        }

        return false;
    }

};

int main()
{
    
    return 0;
}