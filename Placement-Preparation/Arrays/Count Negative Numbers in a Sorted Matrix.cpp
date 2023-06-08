#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
        // 4 3 2 1
        // 3 2 1 -1
        // 1 1 -1 -2
        // -1 -1 -2 -3

        int n=grid.size();
        int m=grid[0].size();

        int i=0;
        int j=m-1;

        int count=0;

        while(i<n && j>=0)
        {
            if(grid[i][j]<0)
            {
                count+=(n-i);
                j--;  
            }

            else if(grid[i][j]>=0)
            {
                i++;
            }
            else{
                j--;
            }
        }

        return count;

    }
};

int main()
{
    
    return 0;
}