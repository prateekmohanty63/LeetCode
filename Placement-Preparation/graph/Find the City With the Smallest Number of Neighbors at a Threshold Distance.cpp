#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<climits>
using namespace std;

class Solution {
public:
   
   vector<int> dijk(int src,int n,unordered_map<int,vector<pair<int,int>>>&adj)
   {
       // initilize the distance matrix
       vector<int>dist(n,INT_MAX);

       dist[src]=0;

       // visited matrix
       vector<int>vis(n,-1);
       vis[src]=0;

       // priority queue 
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;

       q.push({0,src});

       // BFS

       while(!q.empty())
       {
           pair<int,int>fr=q.top();
           q.pop();
           int parentNode=fr.second;
           int currCost=fr.first;

           for(auto it:adj[parentNode])
           {
               int childNode=it.first;
               int cost=it.second;

               if(dist[childNode]>currCost+cost){
                   dist[childNode]=cost+currCost;
                   q.push({dist[childNode],childNode});
               }
           }
       }
       return dist;
   }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        // adj matrix
        unordered_map<int,vector<pair<int,int>>>adj;
        
        int m=edges.size();

        for(int i=0;i<m;i++)
        {
            int src=edges[i][0];
            int dest=edges[i][1];
            int wei=edges[i][2];

            adj[src].push_back({dest,wei});
            adj[dest].push_back({src,wei});
        }

       int res;
       int minCount=INT_MAX;

       for(int i=0;i<n;i++)
       {
           vector<int>dist=dijk(i,n,adj);
           int count=0;
           for(auto it:dist)
           {
               if(it<=distanceThreshold){
                 count++;
               }
           }
           if(count<=minCount){
               minCount=count;
               res=i;
           }
       }

        return res;
    }
};

int main()
{
    
    return 0;
}