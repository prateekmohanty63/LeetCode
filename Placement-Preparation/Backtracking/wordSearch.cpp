#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
   
   bool isPresent(vector<vector<char>>&board,int i,int j,string word,int k,vector<vector<bool>>&vis)
   {
       int n=board.size();
       int m=board[0].size();
       // base case
       if(k>=word.length())return true;

       if(i<0 || i>=n)return false;

       if(j<0 || j>=m)return false;

       if(vis[i][j])return false;

       // we can move horitontally or vertically 

       bool ans=false;
       
       if(board[i][j]==word[k])
       {
           vis[i][j]=true;
         ans=(isPresent(board,i+1,j,word,k+1,vis) || isPresent(board,i-1,j,word,k+1,vis) || isPresent(board,i,j+1,word,k+1,vis) || isPresent(board,i,j-1,word,k+1,vis));
         vis[i][j]=false;
       }
      // else return false;

      return  ans;

   }

    bool exist(vector<vector<char>>& board, string word) {
        
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>>vis(n+1,vector<bool>(m+1,false));

      //  cout<<isPresent(board,0,0,word,1);
         
      
        for(int i=0;i<n;i++)
        {
           for(int j=0;j<m;j++)
           {
               if(board[i][j]==word[0])
               {
                   bool a=isPresent(board,i,j,word,0,vis);

                   if(a==true)return true;
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