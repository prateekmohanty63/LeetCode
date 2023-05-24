#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
   
   

   void dfs(int start,unordered_map<int,vector<int>>&adj,unordered_map<int,bool>&vis)
   {
        vis[start]=true;

        for(auto it:adj[start])
        {
            if(!vis[it])
            {
                dfs(it,adj,vis);
            }
           
        }
   }

    int findCircleNum(vector<vector<int>>& isConnected) {
        
       // building the adjacency matrix , we get
       unordered_map<int,vector<int>>adj;
       unordered_map<int,bool>vis;
       int res=0;

       int n=isConnected.size();

       for(int i=0;i<n;i++)
       {
           for(int j=0;j<n;j++)
           {
               if(isConnected[i][j]==1)
               {
                   adj[i].push_back(j);
                   adj[j].push_back(i);
               }
           }
       }
      
      for(int i=0;i<n;i++)
      {
          if(vis.find(i)==vis.end())
          {
              res++;
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