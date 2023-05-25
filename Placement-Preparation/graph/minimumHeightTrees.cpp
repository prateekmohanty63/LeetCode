#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;


class Solution {
public:
    
    int bfs(int start,unordered_map<int,vector<int>>&adj,vector<int>&vis)
    {
       queue<int>q;
       q.push(start);
       vis[start]=1;
       int count=0;

       

       while(!q.empty())
       {
           int a=q.front();
           q.pop();

           for(auto it:adj[a])
           {
               if(vis[it]==0)
               {
                  count=max(count,1+bfs(it,adj,vis));
               }
           }

       }
       return count;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        // building the adjacency matrix

        unordered_map<int,vector<int>>adj;
        vector<int>res;

        int m=edges.size();

        for(int i=0;i<m;i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<pair<int,int>>vec;
       
        for(int i=0;i<n;i++)
        {
           
            vector<int>vis(n,0);
            int height=bfs(i,adj,vis);
            pair<int,int>pr;
            pr.first=i;
            pr.second=height;
            vec.push_back(pr);

        }
       int minimHeight=INT_MAX;
        for(auto it:vec)
        {
            minimHeight=min(minimHeight,it.second);
            cout<<it.first<<" "<<it.second<<endl;
        }
        for(auto it:vec)
        {
            if(it.second==minimHeight)
            {
                res.push_back(it.first);
            }
        }

        return res;
    }
};

int main()
{
    
    return 0;
}