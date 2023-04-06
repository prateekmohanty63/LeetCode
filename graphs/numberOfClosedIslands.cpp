#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


class Solution {
public:
  unordered_map<string,bool>vis;
   int isClosedIslands(vector<vector<int>>&grid,int i,int j)
   {
       // base case

       int n=grid.size();
       int m=grid[0].size();

       if(i<0 || j<0 || j==m || i==n)return 0;

         string a=to_string(i)+"*"+to_string(j);

       if(grid[i][j]==1 || vis.find(a)!=vis.end())return 1;

       
      vis[a]=true;

return min(min(isClosedIslands(grid,i-1,j),isClosedIslands(grid,i+1,j)),min(isClosedIslands(grid,i,j-1),isClosedIslands(grid,i,j+1)));
        
        

   }

    int closedIsland(vector<vector<int>>& grid) {
        
        int numberOfClosedIslands=0;
        int n=grid.size();
        int m=grid[0].size();
        //unordered_map<string,bool>vis;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                string a=to_string(i)+"*"+to_string(j);
                if(grid[i][j]==0 && vis.find(a)==vis.end())
                {
                   numberOfClosedIslands+=isClosedIslands(grid,i,j);
                }
            }
        }
        return numberOfClosedIslands;
    }
};

int main()
{
    
    return 0;
}