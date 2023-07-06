#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// MULTI-SOURCE DFS / BFS

// T(N)=O(log(n)*r*c*c)


class Solution {
public:
     int r,c;
     bool BFS(vector<vector<int>>&cells,int x,int y)
     {
         
         cells[x][y]=1;

         vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};

         queue<pair<int,int>>q;
         q.push({x,y});

         while(!q.empty())
         {
             int currX=q.front().first;
             int currY=q.front().second;
             q.pop();
            

             if(currX==r-1)return true;

             for(int i=0;i<4;i++)
             {
                 int nextX=currX+dir[i][0];
                 int nextY=currY+dir[i][1];

                 if(nextX>=0 && nextX<r && nextY>=0 && nextY<c && cells[nextX][nextY]==0)
                 {
                      q.push({nextX,nextY});
                      cells[nextX][nextY]=1;
                }
             }
         }
         return false;
     }

     bool canReach(vector<vector<int>>&mat)
     {
         vector<vector<int>>vis(r,vector<int>(c,0));
          for(int i=0;i<c;i++)
          {
             if(mat[0][i]==0){
              if(BFS(mat,0,i))return true;
             }
          }
          return false;
     }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        r=row;
        c=col;
        vector<vector<int>>mat;
        mat.resize(r,vector<int>(c,0));
        int n=cells.size();
        
        int start=0;
        int end=n-1;
        int res=0;
 
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            for(int i=0;i<r;i++)
            {
                for(int j=0;j<c;j++)mat[i][j]=0;
            }

            for(int i=0;i<=mid;i++)
            {
                mat[cells[i][0]-1][cells[i][1]-1]=1;
            }

            // for(int i=0;i<r;i++)
            // {
            //     for(int j=0;j<c;j++)cout<<mat[i][j]<<" ";
            //     cout<<endl;
            // }
            cout<<endl;
          
            if(canReach(mat))
            {
                res=mid+1;
                start=mid+1;
            }
            else{
                end=mid-1;
            }
           
        }
        
        return res;
    }
};


// T(N)=O(n*r*c*c)
// TLE

class Solution {
public:
     int r,c;
     bool BFS(vector<vector<int>>&cells,int x,int y)   // O(r*c)
     {
         
         vector<vector<int>>vis(r,vector<int>(c,0));

         vis[x][y]=1;

         vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};

         queue<pair<int,int>>q;
         q.push({x,y});

         while(!q.empty())
         {
             int currX=q.front().first;
             int currY=q.front().second;
             q.pop();
             vis[currX][currY]=1;

             if(currX==r-1)return true;

             for(int i=0;i<4;i++)
             {
                 int nextX=currX+dir[i][0];
                 int nextY=currY+dir[i][1];

                 if(nextX>=0 && nextX<r && nextY>=0 && nextY<c && vis[nextX][nextY]==0 && cells[nextX][nextY]==0)
                 {
                      q.push({nextX,nextY});
                }
             }
         }
         return false;
     }
  
     bool canReach(vector<vector<int>>&mat)     // O(r*c*c)  
     {
         
          for(int i=0;i<c;i++)   // O(c)
          {
             if(mat[0][i]==0){
              if(BFS(mat,0,i))return true;   // O(r*c)
             }
          }
          return false;
     }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        r=row;
        c=col;
        vector<vector<int>>mat(row,vector<int>(col,0));
        int n=cells.size();

        for(int i=0;i<n;i++)
        {
            mat[cells[i][0]-1][cells[i][1]-1]=1;
        }
        for(int i=n-1;i>=0;i--)    // O(n)
        {
            if(canReach(mat))return i+1;   // O(r*c*c)

            mat[cells[i][0]-1][cells[i][1]-1]=0;
        }
        return -1;
    }
};

int main()
{
    
    return 0;
}