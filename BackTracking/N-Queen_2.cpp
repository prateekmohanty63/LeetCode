#include<iostream>
#include<vector>
using namespace std;

// 1st method
//Runtime: 7 ms, faster than 58.17% of C++ online submissions for N-Queens II.
//Memory Usage: 6.7 MB, less than 34.70% of C++ online submissions for N-Queens II.
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

// 2nd method (faster method)
// Runtime: 3 ms, faster than 86.53% of C++ online submissions for N-Queens II.
// Memory Usage: 6.2 MB, less than 61.83% of C++ online submissions for N-Queens II.
class Solution {
public:
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
    
      void dfs(vector<string>&board,int row,int &count)
    {
        // base case
        if(row==board.size()){
            count++;
            return ;
        }
        
        // iterate all possible solution
        
        for(int i=0;i<board.size();i++)
        {
            if(isValid(board,row,i)){
                board[row][i]='Q';
                
                // next iteration
                dfs(board,row+1,count);
                
                // backtrack
                board[row][i]='.';
            }
        }
    }
    int totalNQueens(int n) {
        
        if(n==1)return 1;
        int row=0;
        vector<string>board(n,string(n,'.'));
        
       int  count=0;
        
        dfs(board,row,count);
        
        return count;
        
    }
};

int main()
{
    
    return 0;
}