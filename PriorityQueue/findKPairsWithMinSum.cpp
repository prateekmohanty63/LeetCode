#include<iostream>
#include<vector>
#include<queue>
using namespace std;


// T(N)=O(N^2)
// S(N)=O(K)
// TLE

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        vector<vector<int>>res;

        priority_queue<pair<int,pair<int,int>>>q;

        int n=nums1.size();
        int m=nums2.size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {

                q.push({nums1[i]+nums2[j],{nums1[i],nums2[j]}});

                if(q.size()>k)q.pop();
            }
        }

        while(!q.empty())
        {
            vector<int>vec;
            pair<int,pair<int,int>>fr=q.top();
            q.pop();
            vec.push_back(fr.second.first);
            vec.push_back(fr.second.second);
            res.push_back(vec);
        }
        reverse(res.begin(),res.end());

        return res;
    }
};

int main()
{
    
    return 0;
}