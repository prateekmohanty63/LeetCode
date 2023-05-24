#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
   
   void dfs(vector<vector<char>>&grid,int i,int j,vector<vector<int>>&vis)
   {
       int n=grid.size();
       int m=grid[0].size();
       // base case

       if(i<0 || i>=n)return ;
       if(j<0 || j>=m)return ;

       if(grid[i][j]=='0')return ;

       vis[i][j]=1;

       if(i+1<n && vis[i+1][j]==-1){
          vis[i+1][j]=1;
         dfs(grid,i+1,j,vis);
       }
       if(i-1>=0 && vis[i-1][j]==-1)
       {
           vis[i-1][j]=1;
           dfs(grid,i-1,j,vis);
       }
       if(j+1<m && vis[i][j+1]==-1)
       {
           vis[i][j+1]=1;
           dfs(grid,i,j+1,vis);
       }
       if(j-1>=0 && vis[i][j-1]==-1)
       {
           vis[i][j-1]=1;
           dfs(grid,i,j-1,vis);
       }

   }

    int numIslands(vector<vector<char>>& grid) {
        
        int res=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,-1));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                 if(grid[i][j]=='1' && vis[i][j]==-1)
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