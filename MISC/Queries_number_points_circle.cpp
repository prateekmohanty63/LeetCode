#include <iostream>
#include <vector>
using namespace std;

/// Approach-1

class Solution
{
public:
    vector<int> countPoints(vector<vector<int>> &points, vector<vector<int>> &queries)
    {

        vector<int> res;

        int n = points.size();
        int m = queries.size();

        for (int i = 0; i < m; i++)
        {
            int count = 0;
            int dia_lx = queries[i][0] - queries[i][2];
            int dia_ly = queries[i][1];

            int dia_rx = queries[i][0] + queries[i][2];
            int dia_ry = queries[i][1];

            int dia_ux = queries[i][0];
            int dia_uy = queries[i][1] + queries[i][2];

            int dia_lox = queries[i][0];
            int dia_loy = queries[i][1] - queries[i][2];

            for (int j = 0; j < n; j++)
            {
                int flag = 0;
                int a = points[j][0];
                int b = points[j][1];

                if ((a >= dia_lx && b >= dia_ly) || (a <= dia_rx && b <= dia_ry))
                    flag = 1;

                if ((a >= dia_lox && b >= dia_loy) || (a <= dia_ux && b <= dia_uy))
                    flag = 1;

                if (flag == 1)
                    count++;
            }
            res.push_back(count);
        }
        return res;
    }
};

/// Approach-2

class Solution
{
public:
    bool isInside(int cx, int cy, int r, int x, int y)
    {

        int a = (cx - x) * (cx - x) + (cy - y) * (cy - y);

        if (a <= r * r)
            return true;

        return false;
    }
    vector<int> countPoints(vector<vector<int>> &points, vector<vector<int>> &queries)
    {

        vector<int> res;

        int n = queries.size();
        int m = points.size();

        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < m; j++)
            {
                if (isInside(queries[i][0], queries[i][1], queries[i][2], points[j][0], points[j][1]))
                {
                    count++;
                }
            }
            res.push_back(count);
        }
        return res;
    }
};