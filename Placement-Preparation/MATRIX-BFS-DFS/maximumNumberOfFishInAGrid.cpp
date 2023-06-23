#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

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