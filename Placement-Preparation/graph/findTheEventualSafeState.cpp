#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;


class Solution {
public:
   
   bool dfs(int start,unordered_map<int,vector<int>>&adj,vector<int>&vis,vector<int>&dfsVis,vector<int>&isSafe)
   {
       vis[start]=true;
       dfsVis[start]=true;
       isSafe[start]=false;

     

       for(auto it:adj[start])
       {
           // if the neighbour is not visited
           if(vis[it]==0)
           {
               if(dfs(it,adj,vis,dfsVis,isSafe)){
                   return true;
               }
           }
           else{
               // if it is already visited and is cycle , it is not safe return 
               if(dfsVis[it]==1)return true;

               
           }
       }
       isSafe[start]=true;
       dfsVis[start]=false;

       return false;
   }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        vector<int>res;

        // adjacency matrix
        unordered_map<int,vector<int>>adj;
        
        // number of nodes in graph
        int n=graph.size();

        // storing the safe nodes
        vector<int>isSafe(n,0);

        for(int i=0;i<n;i++)
        {
             adj[i]=graph[i];

        }

        vector<int>vis(n,0);
        vector<int>dfsVis(n,0);

        for(int i=0;i<n;i++){
            if(vis[i]==0)
            dfs(i,adj,vis,dfsVis,isSafe);
        }

        for(int i=0;i<n;i++)
        {
            if(isSafe[i]==1)res.push_back(i);
        }
        return res;
    }
};

int main()
{
    
    return 0;
}