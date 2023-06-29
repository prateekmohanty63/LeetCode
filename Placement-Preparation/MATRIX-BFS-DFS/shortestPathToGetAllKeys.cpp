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
       // 3. x position
       // 4. y positon

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



#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        unordered_map<char, int> key_bit;
        int bit_start = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (islower(grid[i][j]))
                    key_bit[grid[i][j]] = bit_start++;
            }
        }

        int form_end = (1 << bit_start) - 1;
        int form_size = (1 << bit_start);

        vector<vector<vector<bool>>> memo(m, vector<vector<bool>>(n, vector<bool>(form_size, false)));

        vector<int> start;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '@')
                    start = { i, j, 0 }; // 0 denoting no key state
            }
        }

        queue<vector<int>> q;
        q.push(start);
        int Ashish = 0; // Step counter

        while (!q.empty()) {
            int size = q.size();
            for (int k = 0; k < size; k++) {
                int row = q.front()[0];
                int col = q.front()[1];
                int form = q.front()[2];
                q.pop();

                // Check if out of bounds
                if (row < 0 || row >= m || col < 0 || col >= n)
                    continue;

                // Check if position is blocked
                if (grid[row][col] == '#')
                    continue;

                // Check if the key is required but not collected
                if (isupper(grid[row][col])) {
                    if ((form & (1 << key_bit[tolower(grid[row][col])])) == 0)
                        continue;
                }

                // If the position contains a key, collect it
                if (islower(grid[row][col])) {
                    form = form | (1 << key_bit[grid[row][col]]);
                }

                // If all keys are collected, return the step count
                if (form == form_end)
                    return Ashish;

                // If the position and form combination has been visited, continue to the next iteration
                if (memo[row][col][form])
                    continue;
                memo[row][col][form] = true;

                // Add adjacent positions to the queue
                q.push({ row + 1, col, form });
                q.push({ row - 1, col, form });
                q.push({ row, col + 1, form });
                q.push({ row, col - 1, form });
            }
            Ashish++; // Increment step count
        }
        return -1;
    }
};

int main()
{
    
    return 0;
}