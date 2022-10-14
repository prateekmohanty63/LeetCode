#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        int row=-1,col=-1;
        
        for(int i=0;i<n;i++)
        {
            if(matrix[i][0]==target || matrix[i][m-1]==target)return true;
            
            if(matrix[i][0]<target && matrix[i][m-1]>target)row=i;
        }
        
        if(row==-1)return false;
        
        for(int i=1;i<m;i++)
        {
            if(matrix[row][i]==target)return true;
        }
        return false;
    }
};

int main()
{
    
    return 0;
}