#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
  int count=0;

  void dfs(unordered_map<int,vector<pair<int,int>>>&adj,int src,vector<int>&vis)
  {
      // mark the source as visited
      vis[src]=true;

      for(auto it:adj[src])
      {
          
          pair<int,int>pr=it;
          int node=pr.first;
          int original=pr.second;

          if(vis[node]==0){
        if(original==1)count++;
          
          vis[node]=1;
          dfs(adj,node,vis);
          }
      }
  }
    int minReorder(int n, vector<vector<int>>& connections) {
        
        unordered_map<int,vector<pair<int,int>>>adj;

        int m=connections.size();
        
        for(int i=0;i<m;i++)
        {
            pair<int,int>pr;
            pr.first=connections[i][1];
            pr.second=1;

            adj[connections[i][0]].push_back(pr);

            pr.first=connections[i][0];
            pr.second=0;

            adj[connections[i][1]].push_back(pr);
        }
        
        vector<int>vis(n+1,0);
        dfs(adj,0,vis);

        return count;
    }
};

int main()
{
    
    return 0;
}