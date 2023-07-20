#include<iostream>
#include<vector>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
     void dfs(vector<vector<char>>&grid,int x,int y,vector<vector<int>>&vis)
     {
         // base case
         
         int n=grid.size();
         int m=grid[0].size();
         
         if(x<0 || x>=n)return ;
         
         if(y<0 || y>=m)return ;
         
         if(grid[x][y]=='0')return ;
         
         vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{-1,1},{1,-1},{1,1}};
         
         for(int i=0;i<8;i++)
         {
             int nextX=x+dir[i][0];
             int nextY=y+dir[i][1];
             
             if(nextX>=0 && nextX<n && nextY>=0 && nextY<m  && vis[nextX][nextY]==0)
             {
                 vis[nextX][nextY]=1;
                 dfs(grid,nextX,nextY,vis);
             }
         }
         
         
     }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>vis(n+1,vector<int>(m+1,0));
        
        int res=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==0 && grid[i][j]=='1')
                {
                    res++;
                    dfs(grid,i,j,vis);
                }
            }
        }
        return res;
    }
};


int main()
{
    
    return 0;
}