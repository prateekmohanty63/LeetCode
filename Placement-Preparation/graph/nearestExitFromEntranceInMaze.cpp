#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
  
  int minCost(vector<vector<char>>&maze,vector<vector<int>>&vis,vector<int>&entrance)
  {
      int n=maze.size();
      int m=maze[0].size();
      int startx=entrance[0];
      int starty=entrance[1];

      // queue for bfs
      queue<pair<int,pair<int,int>>>pr;

      // push the starting position into queue
      pr.push({0,{startx,starty}});

      // directions
      vector<vector<int>>dir={{-1,0},{1,0},{0,-1},{0,1}};

      while(!pr.empty())
      {
          pair<int,pair<int,int>>fr=pr.front();
          pr.pop();
          int i=fr.second.first;
          int j=fr.second.second;
          int currCost=fr.first;

          // check if the cell is an exit
          if((i==startx && j!=starty) || (j==starty && i!=startx) || (i!=startx && j!=starty))
          {
              if(i==0 || j==0 || i==n-1 || j==m-1)
              {
                  if(maze[i][j]=='.')return currCost;
              }
          }

          // mark the cell visited
          vis[i][j]=1;

          for(int k=0;k<4;k++)
          {
              int nextx=i+dir[k][0];
              int nexty=j+dir[k][1];
              
              if(nextx>=0 && nextx<n && nexty>=0 && nexty<m && vis[nextx][nexty]==0 && maze[nextx][nexty]=='.')
              {
                  vis[nextx][nexty]=1;
                  pr.push({currCost+1,{nextx,nexty}});
              }

          }
      }
      return -1;
  }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        int n=maze.size();
        int m=maze[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
      
        int res=minCost(maze,vis,entrance);

        return res;
    }
};

int main()
{
    
    return 0;
}