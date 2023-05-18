#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    
    int maxPoints(vector<int>&nums,int i,unordered_map<int,int>&mp,unordered_map<int,int>&freqMap)
    {
        // base case
        if(i<0)return 0;

        // we have the option of deleting the element or not deleting it 
        int val=nums[i];
       

        if(mp.find(val-1)!=mp.end())
        {
            int indToGo=mp[val-1];
            return max(val*freqMap[val]+maxPoints(nums,indToGo-1,mp,freqMap),maxPoints(nums,i-1,mp,freqMap));
        }
        else{
            return max(val*freqMap[val]+maxPoints(nums,mp[val]-1,mp,freqMap),maxPoints(nums,i-1,mp,freqMap));
        }
        

    }

    int deleteAndEarn(vector<int>& nums) {
        
        int n=nums.size();
        sort(nums.begin(),nums.end());
        unordered_map<int,int>indMap;
        unordered_map<int,int>freqMap;

        for(int i=0;i<n;i++)
        {
            if(indMap.find(nums[i])!=indMap.end())
            indMap[nums[i]]=min(i,indMap[nums[i]]);

            else indMap[nums[i]]=i;

            freqMap[nums[i]]++;
        }
        for(auto it:indMap)cout<<it.first<<" "<<it.second<<endl;
        cout<<endl;

        for(auto it:freqMap)cout<<it.first<<" "<<it.second<<endl;

        return maxPoints(nums,n-1,indMap,freqMap);
    }
};

int main()
{
    
    return 0;
}