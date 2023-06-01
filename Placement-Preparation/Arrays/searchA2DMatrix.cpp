#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        int row=0;
        int col=m-1;

        while(row<n && col>=0)
        {
            if(matrix[row][col]==target)return true;

            if(target>matrix[row][col])
            {
                row++;
            }
            else{
                col--;
            }
        }
        return false;
    }
};

int main()
{
    
    return 0;
}