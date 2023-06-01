#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;


    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        
        // taking the result array
        vector<int>res;
        
        // building the adjacency matrix
        unordered_map<int,vector<int>>adj;
        
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        // mark all the nodes as not visited initially
        vector<int>visited(N,-1);
        // parent of all the nodes are not known initially 
        vector<int>parent(N,-1);
        
        // queue for BFS
        queue<int>q;
        
        // push the source to the queue 
        q.push(src);
        
        // mark the parent of src as -1
        parent[src]=-1;
        
        // mark the src as visited
        visited[src]=1;
        
        // perform the BFS
        while(!q.empty())
        {
            int fr=q.front();
            q.pop();
            
            // traverse the neighbours of the front element
            for(auto it:adj[fr])
            {
                if(visited[it]==-1)
                {
                    visited[it]=1;
                    parent[it]=fr;
                    q.push(it);
                }
            }
        }
        // printing the parent array
        //for(auto it:parent)cout<<it<<" ";
        
        // calculating the distance to all nodes from source
        
       // printing the path
       int dest=8;
       vector<int>path;
       path.push_back(dest);

       while(dest!=src)
       {
          dest=parent[dest];
          path.push_back(dest);
       }
        
        reverse(path.begin(),path.end());
        return res;
    }

int main()
{
    
    return 0;
}