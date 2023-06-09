#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
#include<queue>
using namespace std;

class Solution {
public:
   
   vector<int> sourceToDest(int n,unordered_map<int,vector<pair<int,int>>>&adj,int source,int dest,int k)
   {
       // distance matrix
       vector<int>dist(n,INT_MAX);

       // mark the source as distance 0
       dist[source]=0;

      

       // queue for BFS
       queue<pair<int,pair<int,int>>>q;

       // push the source into queue
       q.push({0,{source,0}});

       // perform BFS

       while(!q.empty())
       {
           pair<int,pair<int,int>>fr=q.front();
           q.pop();

           int currStop=fr.second.first;
           int currPrice=fr.first;
           int currK=fr.second.second;
           
         //  vis[currStop]=1;


           for(auto it:adj[currStop])
           {
               int nextStop=it.first;
               int price=it.second;

               if(currK<=k && dist[nextStop]>currPrice+price)
               {
                   dist[nextStop]=currPrice+price;
                   q.push({dist[nextStop],{nextStop,currK+1}});
               }
           }
          

       }
       return dist;

   }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        // adjacency matrix

        unordered_map<int,vector<pair<int,int>>>adj;
        
        int m=flights.size();

        for(int i=0;i<m;i++)
        {
            int from=flights[i][0];
            int to=flights[i][1];
            int price=flights[i][2];

            adj[from].push_back({to,price});
        }

        vector<int>dist=sourceToDest(n,adj,src,dst,k);
        int res=dist[dst];

       if(res==INT_MAX)return -1;

        return res;
    }
};

int main()
{
    
    return 0;
}