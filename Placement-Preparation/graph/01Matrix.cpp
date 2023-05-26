#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

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