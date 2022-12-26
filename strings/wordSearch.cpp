#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
     bool isPresent(vector<vector<char>>&board,string word,int x,int y,int i,vector<vector<bool>>&isVisited)
     {
         // base case
         if(i==word.length())return true;



         if(x>=board.size() || x<0)return false;

         if(y>=board[0].size() || y<0)return false;

          if(board[x][y]!=word[i])return false;

         
          

         if(isVisited[x][y])return false;


         bool ans=false;

         // we have option of moving in four directions

         // left , right , up , dow

         
       if(board[x][y]==word[i]){
           isVisited[x][y]=true;
         ans=(isPresent(board,word,x-1,y,i+1,isVisited) || isPresent(board,word,x+1,y,i+1,isVisited) || isPresent(board,word,x,y-1,i+1,isVisited) || isPresent(board,word,x,y+1,i+1,isVisited));

         isVisited[x][y]=false;
       }

       return ans;
     }

    bool exist(vector<vector<char>>& board, string word) {
        
        int n=board.size();
        int m=board[0].size();
       
       vector<vector<bool>>isVisited(n,vector<bool>(m,false));

      // bool res=false;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {
                   if(isPresent(board,word,i,j,0,isVisited))
                   return true;
                }
            }
        }

           return false;
    }
};

int main()
{
    
    return 0;
}