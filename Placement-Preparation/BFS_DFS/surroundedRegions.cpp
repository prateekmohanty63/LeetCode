#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:

   vector<vector<int>>reach;
   void canReachBoundary(vector<vector<char>>&board,int i,int j,vector<vector<int>>&vis)
   {
       int n=board.size();
       int m=board[0].size();

       // base case
       if(i<0 || i>=n)return ;
       if(j<0 || j>=m)return ;
      
       if(board[i][j]=='X')return ;

       reach[i][j]=1;

       // move up
       if(i-1>=0 && vis[i-1][j]==0)
       {
           vis[i-1][j]=1;
           canReachBoundary(board,i-1,j,vis);
       }

       // move down
       if(i+1<n && vis[i+1][j]==0)
       {
           vis[i+1][j]=1;
           canReachBoundary(board,i+1,j,vis);
       }
       
       // move left
       if(j-1>=0 && vis[i][j-1]==0)
       {
           vis[i][j-1]=1;
           canReachBoundary(board,i,j-1,vis);
       }

       // move right
       if(j+1<m && vis[i][j+1]==0)
       {
           vis[i][j+1]=1;
           canReachBoundary(board,i,j+1,vis);
       }


   } 
 
    void solve(vector<vector<char>>& board) {
        
        int n=board.size();
        int m=board[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        reach.resize(n,vector<int>(m,0));

        // calling dfs from boundaries , to check which all cell can reach boundary
        
        for(int i=0;i<m;i++)
        canReachBoundary(board,0,i,vis);

        for(int i=0;i<m;i++)
        canReachBoundary(board,n-1,i,vis);

        for(int i=0;i<n;i++)
        canReachBoundary(board,i,0,vis);

        for(int i=0;i<n;i++)
        canReachBoundary(board,i,m-1,vis);

        

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O' && reach[i][j]==0)
                {
                    board[i][j]='X';
                }
            }
        }
    }
};

int main()
{
    
    return 0;
}