#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    int solve(int n,unordered_map<int,vector<int>>&adj,unordered_map<int,bool>&restricted)
    {
        vector<int>vis(n,0);
        queue<int>q;
        q.push(0);
        vis[0]=true;
        int res=0;
        while(!q.empty())
        {
             int node=q.front();
             vis[node]=true;
             q.pop();

             for(auto it:adj[node])
             {
                 if(vis[it]==0 && restricted.find(it)==restricted.end())
                 {
                     q.push(it);
                 }
             }
        }

        for(auto it:vis)res+=it;
        return res;
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        
        // making the adjacency matrix
        unordered_map<int,vector<int>>adj;
        unordered_map<int,bool>rest;
        int m=edges.size();

        for(int i=0;i<m;i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int>vis(n,0);

        for(auto it:restricted)
        rest[it]=true;

       if(rest.find(0)!=rest.end())return 0;
          
        int res=solve(n,adj,rest);
            
            

        return res;
    }
};

int main()
{
    
    return 0;
}