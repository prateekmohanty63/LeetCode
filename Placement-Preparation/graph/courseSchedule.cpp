#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:
  
  bool hasCycle(int start,unordered_map<int,vector<int>>&adj,vector<int>&vis)
  {
      // base case
      if(vis[start]==1)return true;

      if(vis[start]==0)
      {
          vis[start]=1;
          for(auto it:adj[start])
          {
              if(hasCycle(it,adj,vis))return true;
          }
      }
      // remove the course from visited set 
      vis[start]=2;
      return false;
  }

    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        
      //  unordered_map<int,vector<int>>adj;
        int n=pre.size();
     

        // adjacency matrix
        unordered_map<int,vector<int>>adj;
        vector<int>vec(numCourses,0);

        for(int i=0;i<n;i++)
        {
            
            adj[pre[i][0]].push_back(pre[i][1]);
            
        }
        for(int i=0;i<numCourses;i++)
        {
            if(hasCycle(i,adj,vec))return false;
             
        } 
        return true;
    }
};

int main()
{
    
    return 0;
}