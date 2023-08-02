#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>&board,int x,int y,char &dir)
    {
          int n=board.size();
          int m=board[0].size();

          if(x<0 || x>=n)return ;
          if(y<0 || y>=m)return ;
          if(board[x][y]=='.')return ;
          
          board[x][y]='.';

          if(dir=='h')
          dfs(board,x,y+1,dir);

          else if(dir=='v')
          dfs(board,x+1,y,dir);
    }
    int countBattleships(vector<vector<char>>& board) {

        int res=0;
        int n=board.size();
        int m=board[0].size();

       // vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='X')
                {
                    res++;
                    board[i][j]='.';
                    if(i+1<n && board[i+1][j]=='X'){
                    char h='v';
                    dfs(board,i+1,j,h);
                    }

                    else if(j+1<m && board[i][j+1]=='X'){
                        char v='h';
                    dfs(board,i,j+1,v);
                    }
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