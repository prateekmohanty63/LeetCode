#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>res;
        vector<int>row1(n,0);
        vector<int>col1(m,0);

        vector<int>row0(n,0);
        vector<int>col0(m,0);

        for(int i=0;i<n;i++)
        {
            int count=0;
            int count1=0;

            for(int j=0;j<m;j++)
            {
                 if(grid[i][j]==1)count++;
                 else count1++;
            }
            row1[i]=count;
            row0[i]=count1;
        }

        for(int i=0;i<m;i++)
        {
             int count=0;
             int count1=0;

             for(int j=0;j<n;j++)
             {
                 if(grid[j][i]==1)count++;
                 else count1++;
             }
             col1[i]=count;
             col0[i]=count1;
        }

        for(int i=0;i<n;i++)
        {
            vector<int>vec;

            for(int j=0;j<m;j++)
            {
                int a=row1[i];
                int b=col1[j];
                int c=row0[i];
                int d=col0[j];

                int num=(a+b-c-d);
                vec.push_back(num);
            }
            res.push_back(vec);
        }
        return res;
    }
};

int main()
{
    
    return 0;
}