#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       
       // Time complexity: O(n)
       // Space complexity: O(n)

       unordered_map<int,int>mp;

       int n=nums.size();

       for(int i=0;i<n;i++)
       {
           if(mp.find(target-nums[i])==mp.end())
           mp[nums[i]]=i;

           else return {mp[target-nums[i]],i};
       }   
       return {};
    }
};


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
       // Time complexity: O(nlogn)
       // space complexity: O(N)

        vector<int>res;
        vector<pair<int,int>>mapping;

        for(int i=0;i<nums.size();i++)
        {
            pair<int,int>pr;
            pr.first=nums[i];
            pr.second=i;
            mapping.push_back(pr);
        }

        sort(mapping.begin(),mapping.end());

        int start=0;
        int end=mapping.size()-1;

        while(start<end)
        {
            cout<<mapping[start].first<<" "<<mapping[start].second<<endl;
            cout<<mapping[end].first<<" "<<mapping[end].second<<endl;

           int sum=mapping[start].first+mapping[end].first;

           if(sum==target)
           {
               res.push_back(mapping[start].second);
               res.push_back(mapping[end].second);
               return res;
           }
           else if(sum<target)start++;

           else end--;
        }
        return res;
    }
};

int main()
{
    
    return 0;
}