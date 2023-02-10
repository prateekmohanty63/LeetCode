#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;


// multi-source BFS (important)
// all test cases passed

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        // The question can be done by finding the distance of nearest land to all water sources
        // then returning the maximum distance from those distances
        // the time complexity would be: O(n^4)

        queue<pair<int,int>>q;

        vector<vector<int>>visited=grid;

        // pushing all lands coordinates to queue

        int n=grid.size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i,j});
                }
            }
        }

        // if no land present

        if(q.size()==0)return -1;

        // if no water present
        if(q.size()==n*n)return -1;

        int distance=-1;

        while(!q.empty())
        {
            int size=q.size();
            

            while(size--)
            {
               auto [x,y]=q.front();
               q.pop();

               // push left coordinated

               if(y-1>=0 && visited[x][y-1]!=2)
               {
                   q.push({x,y-1});
                   visited[x][y-1]=2;
               }

               // push right coordinate

               if(y+1<n && visited[x][y+1]!=2)
               {
                   q.push({x,y+1});
                   visited[x][y+1]=2;
               }

               // push up coordinate

               if(x-1>=0 && visited[x-1][y]!=2)
               {
                   q.push({x-1,y});
                   visited[x-1][y]=2;
               }

               // pushing down coordinated

               if(x+1<n && visited[x+1][y]!=2)
               {
                   q.push({x+1,y});
                   visited[x+1][y]=2;
               }
            }
          
          distance++;
        }
        return distance;
    }
};


// Logic correct
// Giving TLE (19/37) cases passed

class Solution {
public:

class QItem {
public:
    int row;
    int col;
    int dist;
    QItem(int x, int y, int w)
        : row(x), col(y), dist(w)
    {
    }
};

int minDistance(vector<vector<int>>&grid,int i,int j,int N)
{
    vector<vector<bool>>visited(N,vector<bool>(N,false));
    queue<QItem>q;
   QItem source(i, j, 0);
    // make the source visited
    visited[i][j]=true;
    q.push(source);


    while(!q.empty())
    {
        QItem p = q.front();
        q.pop();

         // Destination found;
        if (grid[p.row][p.col] == 1)
            return p.dist;
 
        // moving up
        if (p.row - 1 >= 0 &&
            visited[p.row - 1][p.col] == false) {
            q.push(QItem(p.row - 1, p.col, p.dist + 1));
            visited[p.row - 1][p.col] = true;
        }
 
        // moving down
        if (p.row + 1 < N &&
            visited[p.row + 1][p.col] == false) {
            q.push(QItem(p.row + 1, p.col, p.dist + 1));
            visited[p.row + 1][p.col] = true;
        }
 
        // moving left
        if (p.col - 1 >= 0 &&
            visited[p.row][p.col - 1] == false) {
            q.push(QItem(p.row, p.col - 1, p.dist + 1));
            visited[p.row][p.col - 1] = true;
        }
 
         // moving right
        if (p.col + 1 < N &&
            visited[p.row][p.col + 1] == false) {
            q.push(QItem(p.row, p.col + 1, p.dist + 1));
            visited[p.row][p.col + 1] = true;
        }
 
    }

return -1;
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

      

       int maxDist=INT_MIN;

       for(int i=0;i<n;i++)
       {
           for(int j=0;j<n;j++)
           {
               if(grid[i][j]==0)
               {
                    
                   int dist=minDistance(grid,i,j,n);
                   cout<<i<<" "<<j<<" "<<dist<<endl;
                   maxDist=max(dist,maxDist);
               }
           }
       }
     return maxDist;

    }
};

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