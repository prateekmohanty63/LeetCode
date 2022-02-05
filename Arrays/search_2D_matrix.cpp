#include <iostream>
#include <vector>
using namespace std;

/// 1st approach
/// Giving TLE
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {

        int no_rows = matrix.size();
        int no_cols = matrix[0].size();

        if (no_rows == 1 && no_cols == 1 && matrix[0][0] == target)
            return true;

        if (no_rows == 1 && no_cols == 1 && matrix[0][0] != target)
            return false;
        if (no_rows == 1)
        {
            for (int i = 0; i < no_cols; i++)
            {
                if (matrix[0][i] == target)
                    return true;
            }
            return false;
        }
        if (no_cols == 1)
        {
            for (int i = 0; i < no_rows; i++)
            {
                if (matrix[i][0] == target)
                    return true;
            }
            return false;
        }
        int start = -1;
        int end = -1;

        for (int i = 0; i < no_rows; i++)
        {
            if (target > matrix[i][0])
                start = i;
            else if (target == matrix[i][0])
                return true;
        }

        int k = 0;

        for (int i = no_rows - 1; i >= 0; i--)
        {
            if (target < matrix[i][no_cols - 1])
                end = i;
            else if (target == matrix[i][no_cols - 1])
                return true;
        }

        if (end < start)
            return false;

        for (int i = 0; i < no_cols; i++)
        {
            if (matrix[start][i] == target)
                return true;
        }
        return false;
    }
};

/// 2nd approach

int main()
{

    return 0;
}