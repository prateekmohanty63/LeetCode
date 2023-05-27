#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


class Solution {
public:
    
    void dfs(vector<vector<char>>&grid,int i,int j,vector<vector<int>>&vis)
    {
        // base case

        int n=grid.size();
        int m=grid[0].size();

        if(i<0 || i>=n)return ;
        if(j<0 || j>=m)return ;

        if(grid[i][j]=='0')return ;

        vis[i][j]=1;

        if(i+1<n && vis[i+1][j]==0)
        {
            dfs(grid,i+1,j,vis);
        }
       if(i-1>=0 && vis[i-1][j]==0)
       {
           dfs(grid,i-1,j,vis);
       }
       if(j+1<m && vis[i][j+1]==0)
       {
           dfs(grid,i,j+1,vis);
       }
       if(j-1>=0 && vis[i][j-1]==0)
       {
           dfs(grid,i,j-1,vis);
       }

        
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));

        int count=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && vis[i][j]==0)
                {
                    count++;
                    dfs(grid,i,j,vis);
                }
            }
        }
        return count;
    }
};

class Solution {
public:
   
   

   void dfs(int start,unordered_map<int,vector<int>>&adj,unordered_map<int,bool>&vis)
   {
        vis[start]=true;

        for(auto it:adj[start])
        {
            if(!vis[it])
            {
                dfs(it,adj,vis);
            }
           
        }
   }

    int findCircleNum(vector<vector<int>>& isConnected) {
        
       // building the adjacency matrix , we get
       unordered_map<int,vector<int>>adj;
       unordered_map<int,bool>vis;
       int res=0;

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
      
      for(int i=0;i<n;i++)
      {
          if(vis.find(i)==vis.end())
          {
              res++;
              dfs(i,adj,vis);
          }

      }

       return res;
    }
};

int main()
{
    
    return 0;
}