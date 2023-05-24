#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Solution {
public:
  
  int bfs(vector<vector<int>>&grid,vector<vector<int>>&vis)
  {
      queue<pair<pair<int,int>,int>>q;
      int maxTime=0;
      
      int n=grid.size();
      int m=grid[0].size();

      for(int i=0;i<n;i++)
      {
          for(int j=0;j<m;j++)
          {
              if(grid[i][j]==2)
              {
                  pair<int,int>pr;
                  pair<pair<int,int>,int>r;
                  pr.first=i;
                  pr.second=j;
                  r.first=pr;
                  r.second=0;
                  vis[i][j]=1;
                  q.push(r);
              }
          }
      }
      while(!q.empty())
      {
         pair<pair<int,int>,int>fr=q.front();
         q.pop();
         int i=fr.first.first;
         int j=fr.first.second;
         int time=fr.second;

         // check up pos
         if(i-1>=0 && vis[i-1][j]==-1 && grid[i-1][j]==1)
         {
              grid[i-1][j]=2;
              vis[i-1][j]=1;

              pair<int,int>pr;
              pr.first=i-1;
              pr.second=j;
              pair<pair<int,int>,int>a;
              a.first=pr;
              a.second=(time+1);
              maxTime=max(maxTime,a.second);
              q.push(a);
         }

         // check down pos
         if(i+1<n && vis[i+1][j]==-1 && grid[i+1][j]==1)
         {
             grid[i+1][j]=2;
              vis[i+1][j]=1;

              pair<int,int>pr;
              pr.first=i+1;
              pr.second=j;
              pair<pair<int,int>,int>a;
              a.first=pr;
              a.second=(time+1);
              maxTime=max(maxTime,a.second);
              q.push(a);
         }

         // check left pos
         if(j-1>=0 && vis[i][j-1]==-1 && grid[i][j-1]==1)
         {
             grid[i][j-1]=2;
              vis[i][j-1]=1;

              pair<int,int>pr;
              pr.first=i;
              pr.second=j-1;
              pair<pair<int,int>,int>a;
              a.first=pr;
              a.second=(time+1);
              maxTime=max(maxTime,a.second);
              q.push(a);
         }

         // check right pos
         if(j+1<m && vis[i][j+1]==-1 && grid[i][j+1]==1)
         {
             grid[i][j+1]=2;
              vis[i][j+1]=1;

              pair<int,int>pr;
              pr.first=i;
              pr.second=j+1;
              pair<pair<int,int>,int>a;
              a.first=pr;
              a.second=(time+1);
              maxTime=max(maxTime,a.second);
              q.push(a);
         }
      }

   return maxTime;
  }

    int orangesRotting(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,-1));

        int a=bfs(grid,vis);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)return -1;
            }
        }
        return a;
    }
};

int main()
{
    
    return 0;
}