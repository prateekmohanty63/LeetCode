#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:
   
   bool isCyclic(int start,unordered_map<int,bool>&dfsVis,unordered_map<int,vector<int>>&adj,unordered_map<int,bool>&vis)
   {
         vis[start]=true;
          dfsVis[start]=true;

          for(auto it:adj[start])
          {
              if(vis.find(it)==vis.end())
              {
                  if(isCyclic(it,dfsVis,adj,vis))return true;
              }
              else{
                   if(dfsVis.find(it)!=dfsVis.end())return true;
              }
          }
         dfsVis.erase(start);

         return false;
   }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int,bool>dfsVis;
        unordered_map<int,bool>vis;

        // building the adjacnecy matrix

        unordered_map<int,vector<int>>adj;

        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for(int i=0;i<numCourses;i++)
        {
            if(isCyclic(i,dfsVis,adj,vis))return false;
        }
        return true;
    }
};

int main()
{
    
    return 0;
}