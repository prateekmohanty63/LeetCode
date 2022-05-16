#include <iostream>
#include <vector>
#include <math.h>
#include <climits>
using namespace std;

class Solution
{
public:
    // int count=0;

    void printMatrix(vector<vector<int>> vec1, int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << vec1[i][j] << " ";
            }
            cout << endl;
        }
    }
    bool isSafe(vector<vector<int>> vec1, int i, int j, int n)
    {
        if (i < n && j < n && vec1[i][j] == 0)
            return true;

        return false;
    }

    bool shortestPath(vector<vector<int>> arr, int x, int y, vector<vector<int>> &solArr, int n, int dist, int &minDist)
    {
        if (x == n - 1 && y == n - 1)
        {
            minDist = min(dist, minDist);
            solArr[x][y] = 0;
            printMatrix(solArr, n);
            return true;
        }

        if (isSafe(arr, x, y, n))
        {
            solArr[x][y] = 0;

            // moving towards right side
            if (shortestPath(arr, x, y + 1, solArr, n, dist + 1, minDist))
            {

                return true;
            }

            // moving down
            if (shortestPath(arr, x + 1, y, solArr, n, dist + 1, minDist))
            {
                return true;
            }

            // moving diagonally
            if (shortestPath(arr, x + 1, y + 1, solArr, n, dist + 1, minDist))
            {

                return true;
            }

            // backtrack if all the 3 directions are unsafe
            solArr[x][y] = 1;
            // count--;
            return false;
        }
        return false;
    }
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();

        vector<vector<int>> solArray(n, vector<int>(n, 1));
        int dist = 0;

        int minDist = INT_MAX;

        bool sol = shortestPath(grid, 0, 0, solArray, n, dist, minDist);

        if (sol)
            return minDist;
        return -1;
    }
};

// 2nd method

class Solution
{
public:
    // int count=0;

    void printMatrix(vector<vector<int>> vec1, int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << vec1[i][j] << " ";
            }
            cout << endl;
        }

        cout << endl;
    }
    bool isSafe(vector<vector<int>> vec1, int i, int j, int n)
    {
        if (i < n && j < n && vec1[i][j] == 0)
            return true;

        return false;
    }

    bool shortestPath(vector<vector<int>> arr, int x, int y, vector<vector<int>> &solArr, int n, int dist, int &minDist)
    {
        if (x == n - 1 && y == n - 1)
        {
            minDist = min(dist, minDist);
            solArr[x][y] = 0;
            printMatrix(solArr, n);
            return true;
        }

        if (isSafe(arr, x, y, n))
        {
            solArr[x][y] = 0;
            printMatrix(solArr, n);

            // moving diagonally
            if (shortestPath(arr, x + 1, y + 1, solArr, n, dist + 1, minDist))
            {

                return true;
            }

            // moving towards right side
            if (shortestPath(arr, x, y + 1, solArr, n, dist + 1, minDist))
            {

                return true;
            }

            // moving down
            if (shortestPath(arr, x + 1, y, solArr, n, dist + 1, minDist))
            {
                return true;
            }

            // backtrack if all the 3 directions are unsafe
            solArr[x][y] = 1;
            // count--;
            return false;
        }
        return false;
    }
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();

        vector<vector<int>> solArray(n, vector<int>(n, 1));
        int dist = 0;

        int minDist = INT_MAX;

        bool sol = shortestPath(grid, 0, 0, solArray, n, dist, minDist);

        if (sol)
            return minDist + 1;
        return -1;
    }
};

int main()
{

    return 0;
}