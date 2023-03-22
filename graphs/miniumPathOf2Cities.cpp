#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
#include<map>

using namespace std;

class Solution {
public:
    int minim=INT_MAX;

    void dfs(int source,unordered_map<int,vector<int>>&adj,map<pair<int,int>,int>&cost,unordered_map<int,bool>&vis)
{
    if(vis.find(source)!=vis.end())return ;

    vis[source]=true;

    for(auto it:adj[source])
    {
        int cst=cost[{source,it}];
        minim=min(cst,minim);

        dfs(it,adj,cost,vis);
    }
}

    int minScore(int n, vector<vector<int>>& roads) {
        
        unordered_map<int,vector<int>>adj;
        map<pair<int,int>,int>cost;
        unordered_map<int,bool>vis;

        for(int i=0;i<roads.size();i++)
        {
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
            cost[{roads[i][0],roads[i][1]}]=roads[i][2];
            cost[{roads[i][1],roads[i][0]}]=roads[i][2];
        }

        dfs(1,adj,cost,vis);

        return minim;
    }
};

int main()
{
    
    return 0;
}