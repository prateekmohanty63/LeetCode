#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

class Solution {
public:
  
  vector<vector<int>> bfs(vector<vector<int>>&heights,int x,int y)
  {
      int n=heights.size();
      int m=heights[0].size();


      // queue 
       priority_queue<pair<int, pair<int,int>> ,vector<pair<int, pair<int,int>> >,greater<pair<int,pair<int,int>>>>q;
	    

      // distance 
      vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
      dist[x][y]=0;

     

      // push the start cell to queue
      q.push({0,{x,y}});

      // mark the cell as visited 
      vector<vector<int>>vis(n,vector<int>(m,-1));
      vis[x][y]=1;

      // directions 
      vector<vector<int>>dir={{-1,0},{1,0},{0,-1},{0,1}};

      // BFS

      while(!q.empty())
      {
          pair<int,pair<int,int>>fr=q.top();
          q.pop();
          
          int currx=fr.second.first;
          int curry=fr.second.second;
          // current cell difference
          int currCost=fr.first;

          vis[currx][curry]=1;

       //   if(currx==n-1 && curry==m-1)return currCost;
          
          for(int i=0;i<4;i++)
          {
              int nextx=currx+dir[i][0];
              int nexty=curry+dir[i][1];

              if(nextx>=0 && nextx<n && nexty>=0 && nexty<m && vis[nextx][nexty]==-1)
              {
                 int currDiff=abs(heights[nextx][nexty]-heights[currx][curry]);
                 // max difference of the path
                 int maxDiff=max(currCost,currDiff);
                 if(dist[nextx][nexty]>maxDiff){
            
                    dist[nextx][nexty]=maxDiff;
                   q.push({dist[nextx][nexty],{nextx,nexty}});
                  }

              }
          }

      }
      return dist;
  }

    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n=heights.size();
        int m=heights[0].size();

        vector<vector<int>>res=bfs(heights,0,0);

        return res[n-1][m-1];
    }
};

int main()
{
    
    return 0;
}