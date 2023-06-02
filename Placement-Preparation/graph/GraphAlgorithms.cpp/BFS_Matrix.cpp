#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
   
   int dijk(vector<vector<int>>&grid)
   {
       int n=grid.size();
       // queue for bfs
       queue<pair<int,pair<int,int>>>pr;

       // push the source distance and coordinates into the queue
      
       pr.push({0,{0,0}});

       // now as we proceed we have the mark the cells as visited , hence all the cells that we visit 
       // we will change its value to 1
       
       // storing all the 8 directions for easier traversal
       vector<vector<int>>directions={{1,0},{-1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};

       while(!pr.empty())
       {
            pair<int,pair<int,int>>fr=pr.front();
            pr.pop();

            int currCost=fr.first;

            int i=fr.second.first;
            int j=fr.second.second;
            
            if(i==n-1 && j==n-1)return currCost;
            //cout<<i<<" "<<j<<endl;

            // mark the cell as visited
            grid[i][j]=1;

            for(int k=0;k<8;k++)
            {
                // cout<<"IN";
                int nextI=i+directions[k][0];
                int nextJ=j+directions[k][1];
                
               
                
                if(nextI>=0 && nextI<n && nextJ>=0 && nextJ<n && grid[nextI][nextJ]==0)
                {   
                      grid[nextI][nextJ]=1;
                      pr.push({currCost+1,{nextI,nextJ}});
                }
            }

            
       }
       return -1;
   }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        
        if(grid[0][0]==1 || grid[n-1][n-1]==1)return -1;
        int res= dijk(grid)+1;

        if(n==1){
            if(grid[0][0]==0)return 1;
            
        }

        if(res==0)return -1;

        return res;
    }
};

int main()
{
    
    return 0;
}