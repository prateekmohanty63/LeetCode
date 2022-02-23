#include <iostream>
#include <vector>
using namespace std;


/// Correct solution
// Runtime: 4 ms, faster than 78.24% of C++ online submissions for Search a 2D Matrix.
// Memory Usage: 9.5 MB, less than 78.77% of C++ online submissions for Search a 2D Matrix.


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        int row=-1;
        
        for(int i=0;i<n;i++){
            if(matrix[i][0]<target && matrix[i][m-1]>target){
                row=i;
            }
            
            if(matrix[i][0]==target || matrix[i][m-1]==target)return true;
        }
        
        if(row==-1)return false;
        for(int i=0;i<m;i++){
            if(matrix[row][i]==target)return true;
        }
        cout<<row;
        return false;
    }
};

/// OPTIMIZED SOLUTION 
class Solution {
    
    int binarySearch(vector<int>vec1,int l,int r,int target){
        int mid=l+(r-l)/2;
        
        if(l<=r){
        if(vec1[mid]==target)return mid;
        
        if(target<vec1[mid]){
            return binarySearch(vec1,l,mid-1,target);
        }
        else{
            return binarySearch(vec1,mid+1,r,target);
        }
        }
        return -1;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        int row=-1;
        
        for(int i=0;i<n;i++){
            if(matrix[i][0]<target && matrix[i][m-1]>target){
                row=i;
            }
            
            if(matrix[i][0]==target || matrix[i][m-1]==target)return true;
        }
        
        if(row==-1)return false;
        
        vector<int>vec1=matrix[row];
        
        int r=matrix[row].size();
        
        int index=binarySearch(vec1,0,r-1,target);
        
        if(index!=-1)return true;
        cout<<row;
        return false;
    }
};

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