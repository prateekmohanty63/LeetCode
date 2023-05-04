#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int>res;

        unordered_map<int,int>mp;

        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
         vector<pair<int,int>>mp1;

         for(auto it:mp)
         {
             pair<int,int>pr;
             pr.first=it.second;
             pr.second=it.first;
             mp1.push_back(pr);
         }

         sort(mp1.begin(),mp1.end());

         for(int i=0;i<mp1.size();i++)
         {
             cout<<mp1[i].first<<" "<<mp1[i].second<<endl;
         }
         int l=mp1.size()-1;

         while(k!=0)
         {
             res.push_back(mp1[l].second);
             l--;
             k--;
         }
        return res;
    }
};

int main()
{
    
    return 0;
}