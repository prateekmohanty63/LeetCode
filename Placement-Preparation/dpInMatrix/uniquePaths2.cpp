#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
  
  int numberOfPaths(vector<vector<int>>&obstacleGrid,int i,int j,vector<vector<int>>&vis)
  {
      int m=obstacleGrid.size();
      int n=obstacleGrid[0].size();

        // base case
          

        if(i==m-1 && j==n-1 && obstacleGrid[i][j]==0)return 1; 

         if(i==m-1 && j==n-1 && obstacleGrid[i][j]==1)return 0; 

        if(i<0 || i>=m)return 0;

        if(j<0 || j>=n)return 0;

       if(obstacleGrid[i][j]==1)return 0;

       if(vis[i][j]!=-1)return vis[i][j];
      
        // we can move either down or right
        
        return vis[i][j]=numberOfPaths(obstacleGrid,i+1,j,vis) + numberOfPaths(obstacleGrid,i,j+1,vis);
       
  }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
           
           int m=obstacleGrid.size();
           int n=obstacleGrid[0].size();

           vector<vector<int>>vis(m+1,vector<int>(n+1,-1));

           if(obstacleGrid[0][0]==1)return 0;

           return numberOfPaths(obstacleGrid,0,0,vis);
    }
};

int main()
{
    
    return 0;
}