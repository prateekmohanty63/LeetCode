#include<iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
   
   unordered_map<int,vector<int>>adj;
   unordered_map<int,bool>visited;
  

   int bfs(int rootNode,int parent,vector<bool>&hasApple)
   {
        int count=0;

       for(auto it=adj[rootNode].begin();it!=adj[rootNode].end();it++)
       {
           if(*it==parent)continue;

           int childTime=bfs(*it,rootNode,hasApple);

           if(childTime>0 || hasApple[*it])
           {
               count+=2+childTime;
           }

       }
       return count;
   }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        
         // adjancency list

         int flag=0;

         for(int i=0;i<hasApple.size();i++)
         {
             if(hasApple[i]==true)flag=1;
         }

         if(flag==0)return 0;

         for(int i=0;i<edges.size();i++)
         {
             adj[edges[i][0]].push_back(edges[i][1]);
             adj[edges[i][1]].push_back(edges[i][0]);
         }
         
         int res=bfs(0,0,hasApple);

         return res;
    }
};

int main()
{
    
    return 0;
}