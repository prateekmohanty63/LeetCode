#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;


class Solution{
public:
    vector<vector<int>> chefAndWells(int n,int m,vector<vector<char>> &c){
        // Code here
        
        vector<vector<int>>res(n,vector<int>(m,INT_MAX));
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(c[i][j]=='W')
                {
                    res[i][j]=0;
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                }
                else if(c[i][j]=='N')
                {
                    res[i][j]=0;
                    vis[i][j]=1;
                }
                else if(c[i][j]=='.')
                {
                    res[i][j]=0;
                }
            }
        }
        
        while(!q.empty())
        {
            int currDist=q.front().first;
            int currX=q.front().second.first;
            int currY=q.front().second.second;
            q.pop();
            
            for(int i=0;i<4;i++)
            {
                int nextX=currX+dir[i][0];
                int nextY=currY+dir[i][1];
                
                if(nextX>=0 && nextX<n && nextY>=0 && nextY<m && vis[nextX][nextY]==0)
                {
                    vis[nextX][nextY]=1;
                    res[nextX][nextY]=min(res[nextX][nextY],(currDist+1));
                    q.push({(currDist+1),{nextX,nextY}});
                }
            }
            
            
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                
                if(res[i][j]==INT_MAX)res[i][j]=-1;
                else res[i][j]*=2;
               
            }
        }
        return res;
    }
};

int main()
{
    
    return 0;
}