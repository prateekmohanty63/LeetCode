#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>>vis(m,vector<int>(n,-1));
        queue<vector<int>>q;
        q.push({0,0,k,0}); // x,y,k-val,steps

        while(!q.empty())
        {
            int x=q.front()[0];
            int y=q.front()[1];
            int z=q.front()[2];
            int step=q.front()[3];
            q.pop();

            if(x==m-1 && y==n-1)return step;

            // 4 directions in which we can go in 
            vector<vector<int>>dir{{1,0},{0,1},{-1,0},{0,-1}};

            for(int i=0;i<4;i++)
            {
                int a=x+dir[i][0];
                int b=y+dir[i][1];
                

                if(a<m && a>=0 && b<n && b>=0)
                {
                    if(grid[a][b]==0 && vis[a][b]<z)
                    {
                        q.push({a,b,z,step+1});
                        vis[a][b]=z;
                    }
                    if(grid[a][b]==1 && vis[a][b]<z && z>0)
                    {
                        q.push({a,b,z-1,step+1});
                        vis[a][b]=z;
                    }
                }
            }
        }
        return -1;
    }
};

int main()
{
    
    return 0;
}