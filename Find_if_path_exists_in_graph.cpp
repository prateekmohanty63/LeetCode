#include<iostream>
#include<algorithm>
#include<list>
#include<map>
#include<vector>
#include<unordered_map>
#include<queue>


// using BFS
// Runtime: 981 ms, faster than 53.36% of C++ online submissions for Find if Path Exists in Graph.
// Memory Usage: 207.4 MB, less than 33.15% of C++ online submissions for Find if Path Exists in Graph.

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        // using bfs
        
        if(source==destination)return true;
        
        unordered_map<int,list<int>>adj;
        
        for(auto edge:edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        queue<int>q;
        vector<int>visited(n);
        q.push(source);
        visited[source]=true;
        
        while(!q.empty())
        {
            int front=q.front();
            q.pop();
            for(auto neighbour:adj[front])
            {
                if(!visited[neighbour]){
                if(neighbour==destination)return true;
                visited[neighbour]=true;
                
                q.push(neighbour);
                }
            }
        }
        return false;
    }
};



class Solution {
public:
    unordered_map<int,bool>visited;
    unordered_map<int,list<int>>adj;
    
    bool dfs(int source,int destination)
    {
        visited[source]=true;
        
        for(auto neighbour:adj[source])
        {
            if(!visited[neighbour])
            {
                if(neighbour==destination)return true;
                
                if(dfs(neighbour,destination))return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source==destination)return true;
        
        for(auto edge:edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        return dfs(source,destination);
        
}
};

using namespace std;

// Code correct 
// all test cases passing
// but giving TLE
//26 / 26 test cases passed, but took too long.


class Graph
{
    public:
      map<int,bool>visited;
     map<int,list<int>>adj;
    
    void addEdge(int v,int w);
    
    void hasPath(int v,vector<int>&vec1);
};

void Graph::addEdge(int v,int w)
{
    adj[v].push_back(w);
}

void Graph::hasPath(int source,vector<int>&path)
{
    // visiting the source node first
    // marking the visited node as true
    visited[source]=true;
    path.push_back(source);
    
    // now recursively calling the function for its         neightbouring nodes
    
    for(auto i=adj[source].begin();i!=adj[source].end();i++)
    {
        if(!visited[*i])
        {
            hasPath(*i,path);
        }
    }
    
}

class Solution {
public:
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        Graph g;
        
        
        for(int i=0;i<edges.size();i++)
        {
            g.addEdge(edges[i][0],edges[i][1]);
        }
        
        for(int i=0;i<edges.size();i++)
        {
            g.addEdge(edges[i][1],edges[i][0]);
        }
        vector<int>path;
        g.hasPath(source,path);
        
        for(int i=0;i<path.size();i++)
        {
            cout<<path[i]<<"";
        }
        
        if(find(path.begin(),path.end(),destination)!=path.end())return true;
        
        return false;
    }
};


int main()
{

}