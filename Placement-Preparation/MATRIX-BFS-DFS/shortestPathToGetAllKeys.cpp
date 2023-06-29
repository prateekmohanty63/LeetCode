#include<iostream>
#include<unordered_map>
#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
    int solve(vector<string>&grid,int x,int y,int keyMask)
    {
        int n=grid.size();
        int m=grid[0].size();

       queue<pair<pair<int,int>,pair<int,int>>>q;

       // push the start into queue
       
       // 1. number of moves taken
       // 2. mask keys taken
       // 3. x pos
       // 4. y pos

       q.push({{0,0},{x,y}});

         vector<vector<vector<int>>> vis(n+1, vector<vector<int>>(m+1, vector<int>(keyMask+1,0)));
        // mark the start as visited
        vis[x][y][0]=1;

        // 4 directions
        vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};

        // keys gathered
        unordered_map<char,bool>keyMap;
        keyMap['A']=0;
        keyMap['B']=1;
        keyMap['C']=2;
        keyMap['D']=3;
        keyMap['E']=4;
        keyMap['F']=5;

        keyMap['a']=0;
        keyMap['b']=1;
        keyMap['c']=2;
        keyMap['d']=3;
        keyMap['e']=4;
        keyMap['f']=5;

        while(!q.empty())
        {
            pair<pair<int,int>,pair<int,int>>tp=q.front();
            q.pop();

            int moves=tp.first.first;
            int mask=tp.first.second;
            int currX=tp.second.first;
            int currY=tp.second.second;
            vis[currX][currY][mask]=1;

            cout<<mask<<" ";            
            
            // we have gathered all the keys
            if(mask==keyMask)return moves;

            for(int i=0;i<4;i++)
            {
                int nextX=currX+dir[i][0];
                int nextY=currY+dir[i][1];
                

                if(nextX>=0 && nextX<n && nextY>=0 && nextY<m && vis[nextX][nextY][mask]==0)
                {
                    if(grid[nextX][nextY]>='A' && grid[nextX][nextY]<='F')
                    {
                        // it is a lock
                        int bit=keyMap[grid[nextX][nextY]];
                        int hasKey=mask&(1<<bit);

                        if(hasKey==1)
                        {
                           
                            q.push({{moves+1,mask},{nextX,nextY}});
                        }
                    }
                    else if(grid[nextX][nextY]>='a' && grid[nextX][nextY]<='f')
                    {
                        int bit=keyMap[grid[nextX][nextY]];
                        int newMask=(mask)|(1<<bit);
                        
                        
                        q.push({{moves+1,newMask},{nextX,nextY}});
                    }
                    else if(grid[nextX][nextY]=='.')
                    {
                       
                        q.push({{moves+1,mask},{nextX,nextY}});
                    }
                }
            }
        }

   return -1;
    }
    int shortestPathAllKeys(vector<string>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();

        int numberOfKeys=0;
        int reqMask=0;

        int startx,starty;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='@')
                {
                    startx=i;
                    starty=j;
                }
                if(grid[i][j]=='a')
                reqMask=reqMask|(1<<0);
                
                else if(grid[i][j]=='b')
                reqMask=reqMask|(1<<1);
                
                else if(grid[i][j]=='c')
                reqMask=reqMask|(1<<2);
                
                else if(grid[i][j]=='d')
                reqMask=reqMask|(1<<3);

                else if(grid[i][j]=='e')
                reqMask=reqMask|(1<<4);

                else if(grid[i][j]=='f')
                reqMask=reqMask|(1<<5);
            }
        }
   //  cout<<reqMask;
      int res=solve(grid,startx,starty,reqMask);

      return res;
    }
};

int main()
{
    
    return 0;
}