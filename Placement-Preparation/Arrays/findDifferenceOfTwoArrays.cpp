#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>res;

        unordered_map<int,bool>mp;
        unordered_map<int,bool>mp1;

        int n=nums1.size();
        int m=nums2.size();

        for(int i=0;i<n;i++)
        {
            mp[nums1[i]]=true;
        }
        for(int i=0;i<m;i++)
        {
            mp1[nums2[i]]=true;
        }
        
        vector<int>vec1,vec2;
        for(auto it:mp)
        {
           if(mp1.find(it.first)==mp1.end())vec1.push_back(it.first);
        }

        for(auto it:mp1)
        {
            if(mp.find(it.first)==mp.end())vec2.push_back(it.first);
        }
        res.push_back(vec1);
        res.push_back(vec2);

        return res;
    }
};

int main()
{
    
    return 0;
}