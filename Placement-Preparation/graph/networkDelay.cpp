#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
#include<stack>
using namespace std;

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