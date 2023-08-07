#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<climits>

using namespace std;

class Solution {
public:
   
   int mod=1e9+7;
   vector<int> dijk(int n,unordered_map<int,vector<pair<int,int>>>&adj,int source)
   {
       // distance vector
       vector<int>dist(n+1,INT_MAX);
       dist[source]=0;
       vector<int>vis(n+1,0);

       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
       q.push({0,source});

       vis[source]=true;

       while(!q.empty())
       {
           int node=q.top().second;
           int currDist=q.top().first;
           q.pop();
           vis[node]=true;

           for(auto it:adj[node])
           {
               int child=it.first;
               int cost=it.second;

               if(vis[child]==0 && dist[child]>currDist+cost)
               {
                   dist[child]=currDist+cost;
                   q.push({dist[child],child});
               }
           }
       }
       return dist;
   }
 
   int solve(unordered_map<int,vector<pair<int,int>>>&adj,int start,vector<int>&dist,vector<int>&dp)
   {
       if(start==1){
          return 1;
       }

       if(dp[start]!=-1)return dp[start];

       int sum=0;

       for(auto& it:adj[start])
       {
           int weight=dist[start];
           int val=dist[it.first];

           if(val>weight)
           sum=(sum%mod+solve(adj,it.first,dist,dp)%mod)%mod;
       }
       return dp[start]=sum%mod;

   }
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        
        // making the adjacency matrix
       unordered_map<int, vector<pair<int, int>>> gp;
        for (auto& edge : edges) {
            gp[edge[0]].push_back({edge[1], edge[2]});
            gp[edge[1]].push_back({edge[0], edge[2]});
        }
        
        vector<int> dp(n + 1, -1);
        vector<int>dist=dijk(n,gp,n);
        
        // for(auto it:dist)cout<<it<<" ";

        int res=solve(gp,n,dist,dp);
        return res;
    }
};

int main()
{
    
    return 0;
}