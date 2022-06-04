#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    
    bool isValid(vector<string>&board,int row,int col)
    {
        // check col
        for(int i=row;i>=0;i--)
        {
            if(board[i][col]=='Q')return false;
        }
        
        // check left diagonal
        for(int i=row,j=col;i>=0 && j>=0;--i,--j){
            if(board[i][j]=='Q')return false;
        }
        
        // check right diagonal
        for(int i=row,j=col;i>=0 && j<board.size();--i,++j)
        {
            if(board[i][j]=='Q')return false;
        }
        
        return true;
    }
    
    void dfs(vector<string>&board,int row,vector<vector<string>>&res)
    {
        // base case
        if(row==board.size()){
            res.push_back(board);
            return ;
        }
        
        // iterate all possible solution
        
        for(int i=0;i<board.size();i++)
        {
            if(isValid(board,row,i)){
                board[row][i]='Q';
                
                // next iteration
                dfs(board,row+1,res);
                
                // backtrack
                board[row][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        int row=0;
        vector<string>board(n,string(n,'.'));
        
        dfs(board,0,res);
        
        return res;
    }
};

int main()
{
    
    return 0;
}