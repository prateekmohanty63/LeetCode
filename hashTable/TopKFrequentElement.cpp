#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

// Runtime: 21 ms, faster than 71.35% of C++ online submissions for Top K Frequent Elements.
// Memory Usage: 13.8 MB, less than 24.99% of C++ online submissions for Top K Frequent Elements.

class Solution {
public:
    
    static bool cmp(pair<int,int>&a,pair<int,int>&b)
    {
        return a.second>b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
     
        vector<int>res;
        
        unordered_map<int,int>freq;
        
        for(int i=0;i<nums.size();i++)
        {
            freq[nums[i]]++;
        }
        
        vector<pair<int,int>>pairVec;
        
        
        for(auto it:freq)
        {
            pairVec.push_back(it);
        }
        
        sort(pairVec.begin(),pairVec.end(),cmp);
        
        
        
        for(auto it:pairVec)
        {
            if(k==0)break;
            res.push_back(it.first);
            k--;
        }
        
        return res;
    }
};

int main()
{
    
    return 0;
}