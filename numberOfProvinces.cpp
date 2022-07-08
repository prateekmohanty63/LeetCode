#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;


class Solution {
public:
    bool explore(unordered_map<int,list<int>>&adj,unordered_map<int,bool>&visited,int node)
    {
       if(visited[node]==true)return false;
        visited[node]=true;
         for(auto current:adj[node])
         {
             explore(adj,visited,current);
         }
        return true;
    }
    
    int connectedComponents(unordered_map<int,list<int>>adj)
    {
        int count=0;
        unordered_map<int,bool>visited;
        
        for(auto current:adj)
        {
            if(explore(adj,visited,current.first))count++;
        }
        return count;
    }
    unordered_map<int,list<int>>adj;
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        // making the adjacency list
        int n=isConnected.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        
        }
        int numberOfComponents=connectedComponents(adj);
        return numberOfComponents;
    }
};