#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Solution {
public:
   
   vector<pair<pair<int,int>,pair<int,int>>> dijk(vector<vector<int>>&grid,vector<vector<int>>&mat,vector<int>&start)
   {
       int n=grid.size();
       int m=grid[0].size();

       int i=start[0];
       int j=start[1];
       // queue for doing BFS
       queue<pair<int,pair<int,int>>>pr;

       // distance matrix
       vector<pair<pair<int,int>,pair<int,int>>>dist;

       // marking the source as 0 distance
      
       pr.push({0,{i,j}});

       // marking the start cell as visited 
       grid[i][j]=0;

       // direction vector
       vector<vector<int>>directions={{-1,0},{1,0},{0,-1},{0,1}};

       // performing the BFS
       while(!pr.empty())
       {
           pair<int,pair<int,int>>fr=pr.front();
           int currCost=fr.first;
           pr.pop();

           int currI=fr.second.first;
           int currJ=fr.second.second;
           int currPrice=mat[currI][currJ];

            dist.push_back({{currCost,currPrice},{currI,currJ}});

           for(int k=0;k<4;k++)
           {
               int nextI=currI+directions[k][0];
               int nextJ=currJ+directions[k][1];

               // checking if the cell lie with the constraints
               
               if(nextI>=0 && nextI<n && nextJ>=0 && nextJ<m && grid[nextI][nextJ]!=0)
               {
                   grid[nextI][nextJ]=0;
                  
                    pr.push({currCost+1,{nextI,nextJ}});

               }
           }


       }
       return dist;
   }

    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        
        // finding out the cells which lie within the price range
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>res;

        vector<vector<int>>orgGrid=grid;
        

        // finding out the minimum distance of each cell from the source
       vector<pair<pair<int,int>,pair<int,int>>> dist;
      
        dist=dijk(grid,orgGrid,start);

        sort(dist.begin(),dist.end());
        for(auto it:dist)
        {    // price , distance , i ,j 
              if(k==0)break;
              int price=it.first.second;

              if(price>=pricing[0] && price<=pricing[1]){
                  res.push_back({it.second.first,it.second.second});
                  k--;
              }
           
        }
       
     
     return res;
    }
};

int main()
{
    
    return 0;
}