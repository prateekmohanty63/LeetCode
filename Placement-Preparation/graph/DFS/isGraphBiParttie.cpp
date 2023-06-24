#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool solve(unordered_map<int,vector<int>>&adj,int src,unordered_map<int,int>&vis,unordered_map<int,int>&col)
    {
        // blue=1 , red=0;

           // mark the src as visited
           vis[src]=1;

           int count1=0;
           int count0=0;

           for(auto it:adj[src])
           {
               if(col.find(it)!=col.end() && col[it]==1)count1++;
               else if(col.find(it)!=col.end() && col[it]==0)count0++;
           }
          
        
           if(count1==0)col[src]=1;
           else if(count0==0)col[src]=0;
           else return false;
       
           
           // traverse the neighbours of the current source
           for(auto it:adj[src])
           {
              // if(col.find(src)!=col.end() && col.find(it)!=col.end() && col[it]==col[src])return false;

                if(vis.find(it)==vis.end())
                {
                    vis[it]=1;
                   if(solve(adj,it,vis,col)==false)return false;
                    
                }

                
           }
           return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        // building the adjacenec matrix
        unordered_map<int,vector<int>>adj;

        int n=graph.size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                adj[i].push_back(graph[i][j]);
                adj[graph[i][j]].push_back(i);
            }
        }

        unordered_map<int,int>vis;
        unordered_map<int,int>col;

        for(int i=0;i<n;i++)
        {
            if(vis.find(i)==vis.end()){
               
                if(!solve(adj,i,vis,col))return false;
            }
        }
        cout<<endl;
        for(auto it:col)cout<<it.first<<" "<<it.second<<endl;
        return true;
    }
};

int main()
{
    
    return 0;
}