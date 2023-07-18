#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Solution
{
public:
    int solve(vector<vector<int>> &grid, int k)
    {
        int n = grid.size();
        int m = grid[0].size();

        // queue for BFS
        queue<pair<pair<int, int>, pair<int, int>>> q;

        // push the source to q
        q.push({{0, 0}, {0, k}});

        // direction vector
        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // visited array
        vector<vector<int>> vis(n + 1, vector<int>(m + 1, -1));

        while (!q.empty())
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int steps = q.front().second.first;
            int kLeft = q.front().second.second;

            q.pop();

            if (x == n - 1 && y == m - 1)
                return steps;

            for (int i = 0; i < 4; i++)
            {
                int nextX = x + dir[i][0];
                int nextY = y + dir[i][1];

                if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m)
                {
                    // check if the position is already visited
                    if (vis[nextX][nextY] == -1)
                    {
                        if (grid[nextX][nextY] == 0)
                        {
                            q.push({{nextX, nextY}, {steps + 1, kLeft}});
                            vis[nextX][nextY] = kLeft;
                        }
                        else
                        {
                            // obstacle

                            if (kLeft > 0)
                            {

                                q.push({{nextX, nextY}, {steps + 1, kLeft - 1}});
                                vis[nextX][nextY] = kLeft - 1;
                            }
                        }
                    }
                    else
                    {
                        // check if we can visit the cell with more k
                        if (grid[nextX][nextY] == 0)
                        {
                            if (vis[nextX][nextY] < kLeft)
                            {
                                q.push({{nextX, nextY}, {steps + 1, kLeft}});
                                vis[nextX][nextY] = kLeft;
                            }
                        }
                        else
                        {
                            if (vis[nextX][nextY] < kLeft - 1)
                            {
                                q.push({{nextX, nextY}, {steps + 1, kLeft - 1}});
                                vis[nextX][nextY] = kLeft - 1;
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }
    int shortestPath(vector<vector<int>> &grid, int k)
    {
        int res=solve(grid,k);

        return res;
    }
};

int main()
{
    
    return 0;
}