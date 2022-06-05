#include<iostream>
#include<vector>
using namespace std;

// 1st method
class Solution {
public:
    vector<vector<string>>res;
    bool isValid(vector<string>&board,int row,int col)
    {
        // checking column
        for(int i=row;i>=0;i--)
        {
            if(board[i][col]=='Q')return false;
            
        }
        
        // checking left diagonal
        for(int i=row,j=col;i>=0 && j>=0; --i,--j)
        {
            if(board[i][j]=='Q')return false;
        }
        
        // checking right diagonal
        for(int i=row,j=col;i>=0 && j<board.size();--i,++j){
            if(board[i][j]=='Q')return false;
        }
        
        return true;
    }
    
      void dfs(vector<string>&board,int row)
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
                dfs(board,row+1);
                
                // backtrack
                board[row][i]='.';
            }
        }
    }
    int totalNQueens(int n) {
        
        if(n==1)return 1;
        int row=0;
        vector<string>board(n,string(n,'.'));
        
       
        
        dfs(board,row);
        
        return res.size();
        
    }
};

int main()
{
    
    return 0;
}