#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
using namespace std;

class Solution {
public:
    vector<pair<int,int>>nodeRem;
    map<pair<int,int>,bool>present;
    bool isCycle(int start,int parent,unordered_map<int,vector<int>>&adj,unordered_map<int,bool>&vis)
    {
        vis[start]=1;

        for(auto it:adj[start])
        {
             if(vis.find(it)==vis.end())
             {
                 isCycle(it,start,adj,vis);
             }
             else{
                 if(it!=parent){
                     pair<int,int>pr;

                     if(it<start){
                     pr.first=it;
                     pr.second=start;
                 } 
                 else{
                     pr.first=start;
                     pr.second=it;
                 }
                 if(present.find(pr)==present.end())
                    nodeRem.push_back(pr);
                    present[pr]=true;
                  
                 }
                
             }
            
        }
         return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        // making the adjacency matrix
        unordered_map<int,vector<int>>adj;
      //  sort(edges.begin(),edges.end());
        unordered_map<int,bool>vis;
        map<vector<int>,int>edgeInd;

         for(int i=0;i<edges.size();i++)
         {
             edgeInd[edges[i]]=i;
         }

        int n=edges.size();

        for(int i=0;i<n;i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

       
        int maxInd=INT_MIN;
        for(int i=1;i<n;i++){
            unordered_map<int,bool>vis;
          isCycle(i,-1,adj,vis);
        }

       for(auto it:nodeRem){
          cout<<it.first<<" "<<it.second<<endl;
          vector<int>vec;
          vec.push_back(it.first);
          vec.push_back(it.second);
          maxInd=max(maxInd,edgeInd[vec]);
       }
        
        // cout<<maxInd;
        // return edges[maxInd];
        return edges[maxInd];
    }
};

int main()
{


    return 0;
}