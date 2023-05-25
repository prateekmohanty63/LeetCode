#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<priority_queue>
using namespace std;

class Solution {
public:

 
static bool sortrev(const pair<int,int> &a,  const pair<int,int> &b) 
{ 
  return (a.first > b.first); 
}
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
       vector<pair<int,int>>vec;
       int n=nums1.size();
       long long res=LONG_MIN;

       for(int i=0;i<nums1.size();i++)
       {
           pair<int,int>pr;
           pr.first=nums2[i];
           pr.second=nums1[i];
           vec.push_back(pr);
       }

       sort(vec.begin(),vec.end(),sortrev);
       for(auto it:vec)
       cout<<it.first<<" "<<it.second<<endl;
       
       for(int i=k-1;i<n;i++)
       {
           int currMin=vec[i].first;
           long long sum=vec[i].second;
           int numRem=k-1;
           priority_queue<int>pq;
           for(int j=0;j<i;j++)
           {
               pq.push(vec[j].second);
           }
           while(numRem!=0)
           {
               sum+=pq.top();
               pq.pop();
               numRem--;
           }
          
           res=max(res,currMin*sum);

       }

        return res;
    }
};

int main()
{
    
    return 0;
}