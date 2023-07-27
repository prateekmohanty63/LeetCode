#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>res=board;
        

        vector<vector<int>>dir={{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int countLiveNeigh=0;
                for(int k=0;k<8;k++)
                {
                    int nextX=i+dir[k][0];
                    int nextY=j+dir[k][1];

                    if(nextX>=0 && nextX<n && nextY>=0 && nextY<m)
                    {
                        if(res[nextX][nextY]==1)
                        countLiveNeigh++;
                    }
                }
                if(countLiveNeigh<2)
                board[i][j]=0;

                else if(countLiveNeigh>3)
                board[i][j]=0;

                else if(countLiveNeigh==3)
                board[i][j]=1;

            }
        }
       
    }
};

int main()
{
    
    return 0;
}