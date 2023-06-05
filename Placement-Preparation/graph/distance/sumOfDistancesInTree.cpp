#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<climits>


using namespace std;


class Solution {
public:
   
   long root_result=0;
   vector<int>count;
   int N;

   int dfsBase(unordered_map<int,vector<int>>&adj,int curr_node,int prev_node,int curr_depth){

       int total_count=1;

       root_result+=curr_depth;

       for(int &child:adj[curr_node])
       {
           if(child==prev_node)
           continue;

           total_count+=dfsBase(adj,child,curr_node,curr_depth+1);
       }
       count[curr_node]=total_count;

       return total_count;

   }

   void DFS(unordered_map<int,vector<int>>&adj,int parent_node,int prev_node,vector<int>&result)
   {
       for(int &child:adj[parent_node]){
           if(child==prev_node)continue;

             result[child]=result[parent_node]-count[child]+(N-count[child]);
             DFS(adj,child,parent_node,result);
       }
     
   }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;

        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        N=n;
        count.resize(n,0);
        
        root_result=0;

        dfsBase(adj,0,-1,0);

        vector<int>result(n,0);

        result[0]=root_result;

        DFS(adj,0,-1,result);

        return result;
    }
};


// T(N)=O(N*(E+V))+O(N^2)

class Solution {
public:
     
     vector<int> dijk(unordered_map<int,vector<int>>&adj,int start,int n)
     {
         // distance matrix
         vector<int>dist(n,INT_MAX);

         // visited
         vector<int>vis(n,-1);

         // mark the source as 0
         dist[start]=0;
         vis[start]=1;

         // queue
         queue<pair<int,int>>q;

         // push start into q
         q.push({start,0});
         
         // BFS

         while(!q.empty())             // O(V+E)
         {
             pair<int,int>pr=q.front();
             q.pop();
             int parentNode=pr.first;
             int parentCost=pr.second;

             for(auto it:adj[parentNode]) 
             {
                  if(vis[it]==-1 && dist[it]>dist[parentNode]+1)
                  {
                      vis[it]=1;
                      dist[it]=dist[parentNode]+1;
                      q.push({it,dist[it]});
                  }
             }
         }
         return dist;
     }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        vector<int>res;

        // adjacency matrix
        unordered_map<int,vector<int>>adj;
        int m=edges.size();

        for(int i=0;i<m;i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
       for(int i=0;i<n;i++){                      // O(N)
          vector<int>vec=dijk(adj,i,n);
           int sum=0;
           for(int j=0;j<vec.size();j++)sum+=vec[j];    // O(N)
           res.push_back(sum);
        }

       

        return res;
    }
};

int main()
{
    
    return 0;
}