#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n=nums.size();
        vector<int>res;

        unordered_map<int,int>mp;

        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }

        // building a min heap

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pr;

       for(auto it:mp)
       {
           pair<int,int>p;
           p.first=it.second;
           p.second=it.first;
           pr.push(p);

           if(pr.size()>k)pr.pop();
       }

       while(!pr.empty())
       {
            pair<int,int>tp=pr.top();
            pr.pop();
            res.push_back(tp.second);

       }
       return res;
    }
};

int main()
{
    
    return 0;
}