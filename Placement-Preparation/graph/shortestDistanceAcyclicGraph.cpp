#include<iostream>
#include<unordered_map>
#include<stack>
#include<vector>
#include<climits>
#include<queue>
using namespace std;


// dijkstra algorithm

class Solution {
public:

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        // building the adjacency matrix

        unordered_map<int,vector<pair<int,int>>>adj;
        vector<int>dist(n+1,INT_MAX);
        vector<int>vis(n+1,0);
        
        for(int i=0;i<times.size();i++)
        {
             pair<int,int>pr;
             pr.first=times[i][1];
             pr.second=times[i][2];
             adj[times[i][0]].push_back(pr);
        }
       
         // dijkstra algorithm
         // min heap of pairs
         dist[k]=0;
         priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pr;

         pr.push(make_pair(0,k));

         while(!pr.empty())
         {
             pair<int,int>p=pr.top();
             pr.pop();
             int topNode=p.second;
             vis[topNode]=true;

             for(int i=0;i<adj[topNode].size();i++)
             {
                int node=adj[topNode][i].first;
                int cost=adj[topNode][i].second;

                if(vis[node]==0 && dist[node]>dist[topNode]+cost)
                {
                    dist[node]=dist[topNode]+cost;

                    // push the updated distance
                    pr.push(make_pair(dist[node],node));
                }
             }
         }

    
       int maxTime=INT_MIN;

       for(int i=1;i<dist.size();i++){
           cout<<dist[i]<<" ";
           maxTime=max(maxTime,dist[i]);
       }
       if(maxTime==INT_MAX)return -1;
      return maxTime;
        
    }
};



class Solution {
public:

   stack<int>stk;

   void topoSort(int start,unordered_map<int,vector<vector<int>>>&adj,unordered_map<int,bool>&vis)
   {
       vis[start]=true;
      

       for(auto it:adj[start])
       {
          
           int conn=it[0];
           
           if(vis.find(conn)==vis.end())
           {
               topoSort(conn,adj,vis);
           }
       }
       stk.push(start);
   }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        // building the adjacency matrix

        unordered_map<int,vector<vector<int>>>adj;
        vector<int>dist(n+1,INT_MAX);
        
        for(int i=0;i<times.size();i++)
        {
             vector<int>vec;
             vec.push_back(times[i][1]);
             vec.push_back(times[i][2]);
             adj[times[i][0]].push_back(vec);
        }
       

       // constructing the topo sort
       unordered_map<int,bool>vis;

       for(int i=1;i<=n;i++)topoSort(i,adj,vis);

       // set distance of source to 0
       dist[k]=0;

       while(!stk.empty())
       {
           int tp=stk.top();
           stk.pop();

           if(dist[tp]!=INT_MAX)
           {
               
              
               // checking the connections to the current node and updating the distance 
               for(auto it:adj[tp])
               {
                   vector<int>vec=it;
                   int node=vec[0];
                   int cost=vec[1];
                   
                   if(dist[tp]+cost<dist[node])
                   {
                       dist[node]=dist[tp]+cost;
                   }
               }
           }
       }

    
       int maxTime=INT_MIN;

       for(int i=1;i<dist.size();i++){
           cout<<dist[i]<<" ";
           maxTime=max(maxTime,dist[i]);
       }
       if(maxTime==INT_MAX)return -1;
      return maxTime;
        
    }
};

int main()
{
    
    return 0;
}