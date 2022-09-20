#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int>res;
        
        unordered_map<int,int>mp;
   
        for(auto it:nums)
        {
            mp[it]++;
        }
        
        for(auto it:mp)
        {
            if(it.second>floor(n/3) && it.second!=-1)
            {
                res.push_back(it.first);
                it.second=-1;
                

            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int>res;
        set<int>set1;
        
        unordered_map<int,int>mp;
   
        for(auto it:nums)
        {
            mp[it]++;
        }
        
        for(auto it:mp)
        {
            if(it.second>floor(n/3) && set1.find(it.first)==set1.end())
            {
                res.push_back(it.first);
                set1.insert(it.first);
            }
        }
        return res;
    }
};

int main()
{
    
    return 0;
}