#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
   
   void dfs(int start,unordered_map<int,vector<int>>&adj,vector<int>&vis)
   {
       vis[start]=true;

       for(auto it:adj[start])
       {
           if(vis[it]==0)
           {
               dfs(it,adj,vis);
           }
       }
   }

    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        // building the adjacency matrix
        unordered_map<int,vector<int>>adj;
        vector<int>res;
        vector<int>vis(n,0);
        vector<int>inDegree(n,0);

        int m=edges.size();

        for(int i=0;i<m;i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            inDegree[edges[i][1]]++; 
        }

        for(int i=0;i<inDegree.size();i++)
        {
            if(inDegree[i]==0)
            {
                res.push_back(i);
                dfs(i,adj,vis);
            }
        }
      
      for(int i=0;i<n;i++){
          if(vis[i]==0){
              res.push_back(i);
              dfs(i,adj,vis);
          }
      }
    
    return res;
    }
};

int main()
{
    
    return 0;
}