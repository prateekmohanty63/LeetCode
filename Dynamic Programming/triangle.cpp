#include<iostream>
#include<vector>
using namespace std;

// NOTE RECURSION GIVES TLE


class Solution {
public:
    int minSum(vector<vector<int>>&triangle,int row,int col,int n)
    {
       // base case
        
        if(row==n-1)return triangle[row][col];
        
        int sameRow=triangle[row][col]+minSum(triangle,row+1,col,n);
        int nextRow=triangle[row][col]+minSum(triangle,row+1,col+1,n);
        
        return min(sameRow,nextRow);
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int res=minSum(triangle,0,0,n);
        
        return res;
    }
};

int main()
{
    
    return 0;
}