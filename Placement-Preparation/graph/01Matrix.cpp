#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<queue>
using namespace std;


// BFS SOLUTION

class Solution {
public:
  vector<vector<int>>dir={{0,1},{1,0},{-1,0},{0,-1}};
  bool isValid(int i,int j,int m,int n)
  {
      if(i==m || j==n || i<0 || j<0)return false;

      return true;
  }
  //vector<vector<int>>dir={{1,0},{0,1},{0,-1},{-1,0}};

    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        queue<pair<int,int>>q;
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>dis(m,vector<int>(n,-1));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    q.push({i,j});
                    dis[i][j]=0;
                }
            }
        }

        while(!q.empty())
        {
            pair<int,int>pr=q.front();
            q.pop();

            for(int i=0;i<4;i++)
            {
                int a=pr.first+dir[i][0];
                int b=pr.second+dir[i][1];

                if(isValid(a,b,m,n) && dis[a][b]==-1)
                {
                  q.push({a,b});
                  dis[a][b]=dis[pr.first][pr.second]+1;   
                }
            }
        }
        return dis;
    }
};


// TLE

class Solution {
public:

   vector<vector<int>>dist={{-1,0},{1,0},{0,-1},{0,1}};
   
  
  void dfs(vector<vector<int>>&mat,int i,int j,vector<vector<int>>&vis,int level)
  {
      // base case
      int n=mat.size();
      int m=mat[0].size();
      if(i<0 || i>=n || j<0 || j>=m || (mat[i][j]==0 && level!=0))
      return ;
      
      // there is a shorter path already present
      if(vis[i][j] && mat[i][j]<=level)return ;

      mat[i][j]=level;

      vis[i][j]=1;

      for(int k=0;k<4;k++)
      {
          dfs(mat,i+dist[k][0],j+dist[k][1],vis,level+1);
      }
  }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n=mat.size();
        int m=mat[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        { 
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    dfs(mat,i,j,vis,0);
                }
            }
        }
        return mat;
    }
};

class Solution {
public:
  
  long long distZero(vector<vector<int>>&mat,int i,int j,vector<vector<int>>&vis)
  {
      // base case
      int n=mat.size();
      int m=mat[0].size();
      if(i<0 || i>=n)return INT_MAX;

      if(j<0 || j>=m)return INT_MAX;

      if(mat[i][j]==0)return 0;

      vis[i][j]=1;

      int leftDir=INT_MAX,rightDir=INT_MAX,upDir=INT_MAX,downDir=INT_MAX;

      if(i-1>=0 && vis[i-1][j]==0)
      {
          //vis[i-1][j]=1;
          upDir=1+distZero(mat,i-1,j,vis);
      }
      if(i+1<n && vis[i+1][j]==0)
      {
          //vis[i+1][j]=1;
          downDir=1+distZero(mat,i+1,j,vis);
      }
      if(j-1>=0 && vis[i][j-1]==0)
      {
          //vis[i][j-1]=1;
          leftDir=1+distZero(mat,i,j-1,vis);
      }
      if(j+1<m && vis[i][j+1]==0)
      {
          //vis[i][j+1]=1;
          rightDir=1+distZero(mat,i,j+1,vis);
      }
      return min({upDir,downDir,leftDir,rightDir});
  }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n=mat.size();
        int m=mat[0].size();

        vector<vector<int>>res;

        for(int i=0;i<n;i++)
        {
            vector<int>vec;
             for(int j=0;j<m;j++)
             {
                 if(mat[i][j]==0)
                 {
                     vec.push_back(0);
                 }
                 else{
                     vector<vector<int>>vis(n,vector<int>(m,0));
                     int a=distZero(mat,i,j,vis);
                     vec.push_back(a);
                 }
             }
             res.push_back(vec);
        }
        return res;
    }
};

int main()
{
    
    return 0;
}