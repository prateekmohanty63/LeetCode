#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
  
  void dfs(vector<vector<int>>& a,int i,int j)
  {
      if(i<0 || j<0 || i==a.size() || j==a[i].size() || a[i][j]!=1)return ;
      a[i][j]=0;
      dfs(a,i-1,j);
      dfs(a,i+1,j);
      dfs(a,i,j-1);
      dfs(a,i,j+1);
  }

    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

     for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(i == 0 || j == 0 || i == n-1 || j == m-1)
                {
                    if(grid[i][j] == 1)
                    dfs(grid,i,j);
                }
            }

    }

    int count=0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==1)count++;
        }
    }
    return count;
    }

};

int main()
{
    
    return 0;
}