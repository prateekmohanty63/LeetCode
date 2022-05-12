#include <iostream>
#include <vector>
using namespace std;

int printMatrix(vector<vector<int>> vec1, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << vec1[i][j];
        }
        cout << endl;
    }
}

bool canPlace(vector<vector<int>> vec1, int a, int b)
{
    int j = b;
    // checking the column
    for (int i = 0; i < a; i++)
    {
        if (vec1[i][b] == 1)
            return false;
    }

    // checking the left diagonal

    for (int i = a; i >= 0 && j >= 0; i--, j--)
    {

        if (vec1[i][j] == 1)
            return false;
    }

    // right diagonal

    int i = a;
    while (i >= 0 && j < b)
    {
        if (vec1[i][j] == 1)
            return false;

        i--;
        j++;
    }
    return true;
}

bool Nqueen(vector<vector<int>> vec1, int n, int i)
{

    if (i == n)
    {
        printMatrix(vec1, n);
        return true;
    }

    for (int j = 0; j < n; j++)
    {
        if (canPlace(vec1, i, j))
        {
            vec1[i][j] = 1;

            bool success = Nqueen(vec1, i, j);

            if (success)
                return true;

            // backtrack
            vec1[i][j] = 0;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> vec(n, vector<int>(n, 0));
    bool flag = 0;

    for (int i = 0; i < n; i++)
        Nqueen(vec, i,0);
    return 0;
}