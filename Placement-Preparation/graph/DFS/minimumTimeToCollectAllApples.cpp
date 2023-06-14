#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    
    int collectAllApples(int start,int parent,int n,unordered_map<int,vector<int>>&adj,vector<bool>&hasApple)
    {
        int time=0;
        for(auto it:adj[start])
        {
            if(it==parent)continue;

            int child_time=collectAllApples(it,start,n,adj,hasApple);
            
            // if itss child has apples or itself has apples
            if(child_time>0 || hasApple[it]==true)
            time+=child_time+2;
        }
        return time;
    }
  
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        
        unordered_map<int,vector<int>>adj;

        // building the adjacency matrix
        int m=edges.size();

        for(int i=0;i<m;i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        return collectAllApples(0,-1,n,adj,hasApple);
    }
};

int main()
{
    
    return 0;
}