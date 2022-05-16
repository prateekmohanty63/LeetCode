#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    bool isSafe(vector<vector<int>> &grid, int i, int j, int n, vector<vector<bool>> &visited)
    {

        return (i >= 0 and i < n and j >= 0 and j < n and grid[i][j] == 0 and !visited[i][j]);
    }
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {

        // BFS

        int n = grid.size();

        vector<vector<bool>> visited(n, vector<bool>(n, false));

        queue<pair<int, int>> q;

        int ans = 0;
        int nodePushed;

        if (grid[0][0] == 0)
        {
            q.push({0, 0});
            visited[0][0] = true;
        }

        while (!q.empty())
        {
            nodePushed = q.size();
            ans++;

            for (int c = 0; c < nodePushed; c++)
            {
                pair<int, int> frontNode = q.front();
                q.pop();

                int i = frontNode.first, j = frontNode.second;

                if (i == n - 1 && j == n - 1)
                    return ans;

                for (int k = i - 1; k <= i + 1; k++)
                {
                    for (int l = j - 1; l <= j + 1; l++)
                    {
                        if (isSafe(grid, k, l, n, visited))
                        {
                            q.push({k, l});
                            visited[k][l] = true;
                        }
                    }
                }
            }
        }
        return -1;
    }
};

int main()
{

    return 0;
}