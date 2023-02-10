#include<iostream>
#include<vector>
using namespace std;


// giving stack overflow error

class Solution {
public:

int minDistance(vector<vector<int>>&grid,int i,int j)
{
    // base case

    if(i<0 || i>=grid.size())return 101;

    if(j<0 || j>=grid.size())return 101;


    int left=1+minDistance(grid,i,j-1);
    int right=1+minDistance(grid,i,j+1);
    int up=1+minDistance(grid,i-1,j);
    int down=1+minDistance(grid,i+1,j);

    return min(min(left,right),min(up,down));
}


 int maxDistance(vector<vector<int>>& grid) {
        
        // if no water present in the grid

        int flag=0;

        int n=grid.size();
        int m=grid[0].size();
       
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(grid[i][j]==0)flag=1;
           }
       }

       if(flag==0)return -1;

       // if no land present

       flag=0;

        for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(grid[i][j]==1)flag=1;
           }
       }

       if(flag==0)return -1;

    cout<<minDistance(grid,1,1);

     return 0;

    }
};

int main()
{
    
    return 0;
}