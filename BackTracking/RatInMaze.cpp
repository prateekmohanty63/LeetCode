#include <iostream>
#include <vector>
using namespace std;

void printMatrix(vector<vector<int>> &matrix, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";

        cout << endl;
    }
}

bool isSafe(vector<vector<int>> vec1, int i, int j, int n, int m)
{
    if (i >= 0 && j >= 0 && i < n && j < m && vec1[i][j] == 1)
        return true;

    return false;
}

bool ratInMaze(vector<vector<int>> maze, int x, int y, vector<vector<int>> &sol, int m, int n)
{
    if (x == m - 1 && y == n - 1 && maze[x][y] == 1)
    {
        sol[x][y] = 1;
        printMatrix(sol, m, n);
        return true;
    }

    if (isSafe(maze, x, y, m, n))
    {

        if (sol[x][y] == 1)
            return false;

        sol[x][y] = 1;

        if (ratInMaze(maze, x + 1, y, sol, m, n))
            return true;

        if (ratInMaze(maze, x, y + 1, sol, m, n))
            return true;

        // backtrack
        sol[x][y] = 0;
        return false;
    }
    return false;
}

int main()
{
    vector<vector<int>> vec1;

    int n, m;
    cin >> m >> n;

    for (int i = 0; i < m; i++)
    {
        vector<int> vec2;

        for (int j = 0; j < n; j++)
        {
            int a;
            cin >> a;
            vec2.push_back(a);
        }
        vec1.push_back(vec2);
    }

    vector<vector<int>> sol(m, vector<int>(n, 0));

    ratInMaze(vec1, 0, 0, sol, m, n);
    return 0;
}