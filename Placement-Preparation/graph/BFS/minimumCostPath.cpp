#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
	int solve(vector<vector<int>>&grid)
	{
	    int n=grid.size();
	    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
	    q.push({grid[0][0],{0,0}});
	    vector<vector<int>>vis(n,vector<int>(n,0));
	    vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
	    
	    vis[0][0]=1;
	    
	    while(!q.empty())
	    {
	        int dist=q.top().first;
	        int x=q.top().second.first;
	        int y=q.top().second.second;
	        q.pop();
	        
	        if(x==n-1 && y==n-1)return dist;
	        
	        for(int i=0;i<4;i++)
	        {
	            int currX=x+dir[i][0];
	            int currY=y+dir[i][1];
	            
	            if(currX>=0 && currX<n && currY>=0 && currY<n && vis[currX][currY]==0)
	            {
	                int d=grid[currX][currY];
	                vis[currX][currY]=1;
	                q.push({dist+d,{currX,currY}});
	            }
	        }
	    }
	    return -1;
	}
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        int res=solve(grid);
        
        return res;
    }
};

int main()
{
    
    return 0;
}