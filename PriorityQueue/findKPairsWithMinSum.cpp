#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

// T(N)=O(Klogk)
// S(N)=O(K)

class Solution {
public:
 
   
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // NOTE in priority queue comparator operator is always written opposite to what is required
        
         auto compare=[&](const vector<int>&a,const vector<int>&b){
           return a[0]+a[1]>b[0]+b[1];
       };
        vector<vector<int>>res;

       priority_queue<vector<int>,vector<vector<int>>,decltype(compare)>pq(compare);

       
       for(int i=0;i<nums1.size() && i<k;i++)
       {
           pq.push({nums1[i],nums2[0],0});
       }

       while(k>0 && !pq.empty())     // O(K)
      {
          vector<int>vec=pq.top();
          int currIndex=vec[2];
          pq.pop();
          res.push_back({vec[0],vec[1]});     // O(log(k))
          k--;

          if(currIndex==nums2.size()-1)continue;

          pq.push({vec[0],nums2[currIndex+1],currIndex+1});
          


      }      
      return res;
    }
};

// T(N)=O(n*m*log(k))
// S(N)=O(K)
// TLE

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        vector<vector<int>>res;

        priority_queue<pair<int,pair<int,int>>>q;

        int n=nums1.size();
        int m=nums2.size();

        for(int i=0;i<n;i++)    // O(N)
        { 
            for(int j=0;j<m;j++)   // O(M)
            {

                q.push({nums1[i]+nums2[j],{nums1[i],nums2[j]}});   // log(k)

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