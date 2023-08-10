//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    
 
    
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n=grid.size();
	    int m=grid[0].size();
	    vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
	    vector<vector<int>>vis(n,vector<int>(m,0));
	    vector<vector<int>>res(n,vector<int>(m,INT_MAX));
	    
	    queue<pair<int,pair<int,int>>>q;
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(grid[i][j]==1)
	            {
	                q.push({0,{i,j}});
	                res[i][j]=0;
	                 vis[i][j]=1;
	            }
	        }
	    }
	    
	    while(!q.empty())
	    {
	        int currX=q.front().second.first;
	        int currY=q.front().second.second;
	       
	        int currDist=q.front().first;
	        q.pop();
	        
	        for(int i=0;i<4;i++)
	        {
	            int nextX=currX+dir[i][0];
	            int nextY=currY+dir[i][1];
	            
	            if(nextX>=0 && nextX<n && nextY>=0 && nextY<m && vis[nextX][nextY]==0)
	            {
	                 vis[nextX][nextY]=1;
	                int dist=currDist+1;
	                res[nextX][nextY]=min(res[nextX][nextY],dist);
	                q.push({res[nextX][nextY],{nextX,nextY}});
	                
	            }
	        }
	        
	    }
	    return res;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends