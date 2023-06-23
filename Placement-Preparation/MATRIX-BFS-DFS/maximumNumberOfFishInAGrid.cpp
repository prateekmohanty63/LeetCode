#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<stack>
using namespace std;

// NOTE: This file contains , both BFS , DFS , Iterative DFS codes

// DFS 
class Solution {
public:
    int DFS(vector<vector<int>>&grid,vector<vector<int>>&vis,int x,int y)
    {
       int n=grid.size();
       int m=grid[0].size();

       if(x<0 || x>=n)return 0;
       if(y<0 || y>=m)return 0;

       if(grid[x][y]==0)return 0;
       
       if(vis[x][y]==1)return 0;

       vis[x][y]=1;

       return grid[x][y]+ DFS(grid,vis,x-1,y)+DFS(grid,vis,x+1,y)+DFS(grid,vis,x,y-1)+DFS(grid,vis,x,y+1);

    }
    int findMaxFish(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();

        int res=INT_MIN;
        vector<vector<int>>vis(n+1,vector<int>(m+1,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]!=0 && vis[i][j]==0)
                res=max(res,DFS(grid,vis,i,j));
            }
        }
    
    if(res==INT_MIN)return 0;
     return res;
    }
};

// iterative dfs
class Solution {
public:
    int IDFS(vector<vector<int>>&grid,vector<vector<int>>&vis,int x,int y)
    {
       int n=grid.size();
       int m=grid[0].size();

      // iterative DFS
      stack<pair<int,int>>s;
      s.push({x,y});

      vis[x][y]=1;

      int count=0;

      // dir vector
      vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};

      while(!s.empty())
      {
          int r=s.top().first;
          int c=s.top().second;
          s.pop();

          count+=grid[r][c];

          for(int i=0;i<4;i++)
          {
              int nextR=r+dir[i][0];
              int nextC=c+dir[i][1];

              if(nextR>=0 && nextR<n && nextC>=0 && nextC<m && vis[nextR][nextC]==0 && grid[nextR][nextC]>0)
              {
                  s.push({nextR,nextC});
                  vis[nextR][nextC]=1;
              }
          }
      }

      return count;

    }
    int findMaxFish(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();

        int res=INT_MIN;
        vector<vector<int>>vis(n+1,vector<int>(m+1,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]!=0 && vis[i][j]==0)
                res=max(res,IDFS(grid,vis,i,j));
            }
        }
    
    if(res==INT_MIN)return 0;
     return res;
    }
};



// BFS
class Solution {
public: 
    int solve(vector<vector<int>>grid,int x,int y,vector<vector<int>>&vis)
    {
        int n=grid.size();
        int m=grid[0].size();

        // queue for BFS
        queue<pair<int,int>>q;

        // push source to queue
        q.push({x,y});
        vis[x][y]=1;

        int noFish=grid[x][y];

        // direction vector 
        vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty())
        {
            int currX=q.front().first;
            int currY=q.front().second;
            q.pop();
            vis[currX][currY]=1;

            for(int i=0;i<4;i++)
            {
                int nextX=currX+dir[i][0];
                int nextY=currY+dir[i][1];

                if(nextX>=0 && nextX<n && nextY>=0 && nextY<m && vis[nextX][nextY]==0 && grid[nextX][nextY]>0)
                {
                    noFish+=grid[nextX][nextY];
                    q.push({nextX,nextY});
                    vis[nextX][nextY]=1;
                }
            }
        } 

        return noFish;       
    }
    int findMaxFish(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();

        int res=INT_MIN;

        vector<vector<int>>vis(n+1,vector<int>(m+1,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]!=0 && vis[i][j]==0)
                {
                    res=max(res,solve(grid,i,j,vis));
                }
            }
        }
        if(res==INT_MIN)return 0;
      return res;

    }
};

int main()
{
    
    return 0;
}