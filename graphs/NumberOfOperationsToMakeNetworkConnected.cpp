#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


class Solution {
public:

  bool explore(int node,unordered_map<int,vector<int>>&adj,unordered_map<int,bool>&vis)
  {
      if(vis.find(node)!=vis.end())return false;

      vis[node]=true;

      for(auto it:adj[node])
      {
          if(vis.find(it)==vis.end())
          {
              explore(it,adj,vis);
          }
      }
      return true;
  }
   
   int numberOfComponents(int n,unordered_map<int,vector<int>>&adj)
   {
            int count=0;
            unordered_map<int,bool>mp;

            for(auto it:adj)
            {
                if(explore(it.first,adj,mp)==true)count++;
            }
            return count;
   }

    int makeConnected(int n, vector<vector<int>>& connections) {
        
        // making the adjacency matrix

        int m=connections.size();

        unordered_map<int,vector<int>>adj;

        for(int i=0;i<m;i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        
        int numberOfIsolatedIslands=0;

        for(int i=0;i<n;i++)
        {
            if(adj.find(i)==adj.end())numberOfIsolatedIslands++;
        }
        
        int numberOfConnectionsPresent=0;
         
         for(auto it:adj)
         {
             numberOfConnectionsPresent+=it.second.size();
         }

         numberOfConnectionsPresent/=2;

         if(numberOfConnectionsPresent<n-1)return -1;

         int numberOfcump=numberOfComponents(n,adj)+numberOfIsolatedIslands;

         cout<<numberOfcump;

         return numberOfcump-1;

         
    }
};

int main()
{
    
    return 0;
}