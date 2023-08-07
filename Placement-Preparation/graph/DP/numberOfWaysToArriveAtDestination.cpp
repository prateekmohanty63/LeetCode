#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<climits>

using namespace std;

class Solution {
public:
    int mod=1e9+7;
    int solve(int n,unordered_map<int,vector<pair<int,int>>>&adj)
    {
        vector<long long>distance(n,LONG_MAX);
        vector<int>path(n,0);

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q;
        q.push({0,0});
        distance[0]=0;
        path[0]=1;

        while(!q.empty())
        {
            pair<long long,int>t=q.top();
            q.pop();

            for(auto &it:adj[t.second])
            {
                long long vert=it.first;
                long long edge=it.second;

                if(distance[vert]>distance[t.second]+edge)
                {
                    distance[vert]=distance[t.second]+edge;
                    q.push({distance[vert],vert});
                    path[vert]=path[t.second]%mod;
                }
                // if already the price is same , we have reached the node with same cost
                // we can increment the count of ways it can be visited
                // number of ways to reach a current node is number of ways in which you have reached the previous state
                else if(distance[vert]==t.first+edge)
                {
                    path[vert]+=path[t.second];
                    path[vert]%=mod;
                }
            }
        }
        return path[n-1];
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
        
        int res=solve(n,adj)%mod;
      
       return res%mod;
    }
};

int main()
{
    
    return 0;
}