#include<iostream>
#include<algorithm>
#include<list>
#include<map>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>

using namespace std;


class Solution {
public:
    
    bool explore(vector<vector<char> >&grid,int row,int col,unordered_set<string>&visited)
{
    bool rowInBound=row>=0 && row<grid.size();
    bool columnInBound=col>=0 && col<grid[0].size();

    if(!rowInBound || !columnInBound)return false;

    // check if it is not water
    if(grid[row][col]=='0')return false;


    string pos=to_string(row)+','+to_string(col);
    //cout<<pos<<" ";
    // if that position i visited m return false;
    if(visited.find(pos)!=visited.end())return false;

    visited.insert(pos);

    explore(grid,row-1,col,visited);
    explore(grid,row+1,col,visited);
    explore(grid,row,col-1,visited);
    explore(grid,row,col+1,visited);

    return true;
}
    int numIslands(vector<vector<char>>& grid) {
        // making the adjacency list
      unordered_set<string>visited;
      int n=grid.size();
      int numberOfIslands=0;
      int m=grid[0].size();

      for(int i=0;i<n;i++)
      {
          for(int j=0;j<grid[0].size();j++)
          {
              if(explore(grid,i,j,visited))numberOfIslands++;
          }
      }
    return numberOfIslands;
    }
};