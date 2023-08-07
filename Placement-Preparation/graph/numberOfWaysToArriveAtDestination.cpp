#include<iostream>
#include<unordered_map>
#include<vector>
#include<climits>
#include<queue>

using namespace std;

// TLE 
class Solution {
public:
    int mod=1e9+7;
    int solve(int n,unordered_map<int,vector<pair<int,int>>>&adj)
    {
        vector<int>vis(n,0);
        vector<int>dist(n,INT_MAX);

        vis[0]=true;
        dist[0]=0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;

        q.push({0,0});

        while(!q.empty())
        {
            int node=q.top().second;
            int dis=q.top().first;
            vis[node]=1;
            q.pop();
            
            for(auto it:adj[node])
            {
                int child=it.first;
                int cost=it.second;

                if(vis[child]==0 && dist[child]>dis+cost)
                {
                    dist[child]=dis+cost;
                    q.push({dist[child],child});
                    if(child==n-1)break;
                }
            }
        }
        return dist[n-1];
    }
    int solve(int n,int start,unordered_map<int,vector<pair<int,int>>>&adj,int cost,vector<vector<int>>&dp)
    {
        // base case
        if(start==n-1)return 1;

        if(cost==0)return 0;

        if(dp[start][cost]!=-1)return dp[start][cost];

        int ans=0;

        for(auto it:adj[start])
        {
            int node=it.first;
            int dist=it.second;

            if(dist<=cost)
            ans=(ans+solve(n,node,adj,cost-dist,dp))%mod;
        }
        return dp[start][cost]=ans%mod;
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        
        unordered_map<int,vector<pair<int,int>>>adj;
       
        int m=roads.size();

        for(int i=0;i<m;i++)
        {
            int u=roads[i][0];
            int v=roads[i][1];
            int cost=roads[i][2];

            adj[u].push_back({v,cost});
            adj[v].push_back({u,cost});
        }

       int dist=solve(n,adj);
       //cout<<dist;
        vector<vector<int>>dp(n,vector<int>(dist+1,-1));


       int res=solve(n,0,adj,dist,dp);
       return res;
    }
};

int main()
{
    
    return 0;
}