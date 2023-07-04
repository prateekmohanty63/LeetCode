#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    int count=0;
    int edg=0;
    void solve(int n,int src,unordered_map<int,vector<int>>&adj,vector<int>&vis)
    {
        vis[src]=1;
        edg+=adj[src].size();

        for(auto it:adj[src])
        {
            if(vis[it]==0){
                count++;
            solve(n,it,adj,vis);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
         
         // adjancecy matrix
         unordered_map<int,vector<int>>adj;
         int res=0;

         int m=edges.size();
         vector<int>vis(n,0);

         for(int i=0;i<m;i++)
         {
             adj[edges[i][0]].push_back(edges[i][1]);
             adj[edges[i][1]].push_back(edges[i][0]);
         }
         for(int i=0;i<n;i++)
         {
             if(vis[i]==0){
                
               solve(n,i,adj,vis);
               int noNodes=count+1;
               int noReqEdges=(noNodes)*(noNodes-1);
               if(edg==noReqEdges)res++;
               cout<<count<<" "<<edg<<endl;
               count=0;
               edg=0;
             }
         }
         return res;
    }
};

int main()
{
    
    return 0;
}