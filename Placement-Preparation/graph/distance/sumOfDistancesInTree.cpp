#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<climits>


using namespace std;


// T(N)=O(N*(E+V))+O(N^2)

class Solution {
public:
     
     vector<int> dijk(unordered_map<int,vector<int>>&adj,int start,int n)
     {
         // distance matrix
         vector<int>dist(n,INT_MAX);

         // visited
         vector<int>vis(n,-1);

         // mark the source as 0
         dist[start]=0;
         vis[start]=1;

         // queue
         queue<pair<int,int>>q;

         // push start into q
         q.push({start,0});
         
         // BFS

         while(!q.empty())             // O(V+E)
         {
             pair<int,int>pr=q.front();
             q.pop();
             int parentNode=pr.first;
             int parentCost=pr.second;

             for(auto it:adj[parentNode]) 
             {
                  if(vis[it]==-1 && dist[it]>dist[parentNode]+1)
                  {
                      vis[it]=1;
                      dist[it]=dist[parentNode]+1;
                      q.push({it,dist[it]});
                  }
             }
         }
         return dist;
     }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        vector<int>res;

        // adjacency matrix
        unordered_map<int,vector<int>>adj;
        int m=edges.size();

        for(int i=0;i<m;i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
       for(int i=0;i<n;i++){                      // O(N)
          vector<int>vec=dijk(adj,i,n);
           int sum=0;
           for(int j=0;j<vec.size();j++)sum+=vec[j];    // O(N)
           res.push_back(sum);
        }

       

        return res;
    }
};

int main()
{
    
    return 0;
}