#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


// Count Unreachable Pairs of Nodes in an Undirected Graph

class Solution {
public:

   vector<long long>nodeComponents;

   bool explore(int node,unordered_map<int,vector<int>>&adj,unordered_map<int,bool>&vis,int &count)
   {
       // base case

       if(vis.find(node)!=vis.end())return false;

       vis[node]=true;

       for(auto it:adj[node])
       {
           if(vis.find(it)==vis.end())
           {
               count++;
               explore(it,adj,vis,count);
           }
       }
       return true;
   }

   int noComponents(int n,unordered_map<int,vector<int>>&adj)
   {
       int cnt=0;
       unordered_map<int,bool>vis;
        for(auto it:adj)
        {
            int count=0;
            if(explore(it.first,adj,vis,count))
            {
                nodeComponents.push_back(count+1);
                cnt++;
            }
        }
        return cnt;
   }
  
    long long countPairs(int n, vector<vector<int>>& edges) {
         
         unsigned long long res=0;

        //  if(edges.size()==0){
        //   return n;
        //  }

         // building the adjacency matrix

         unordered_map<int,vector<int>>adj;
         int m=edges.size();

         for(int i=0;i<m;i++)
         {
             adj[edges[i][0]].push_back(edges[i][1]);
             adj[edges[i][1]].push_back(edges[i][0]);
         }

        int l=noComponents(n,adj);

        long long sum=0;

        for(auto it:nodeComponents){
            sum+=it;
        }

       

        while(sum!=n)
        {
            nodeComponents.push_back(1);
            sum++;
        }

          for(auto it:nodeComponents){
          // cout<<it<<" ";
        }

        int k=nodeComponents.size();

         if(nodeComponents.size()==1)return 0;

        
        for(int i=0;i<k;i++)
        {
            sum-=nodeComponents[i];
            unsigned long long cnt=nodeComponents[i]*sum;
            res+=cnt;
        }
        
       

         return res;
    }
};

int main()
{
    
    return 0;
}