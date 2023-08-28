#include<iostream>
#include<vector>
using namespace std;


// 129 / 129 test cases passed.
// Status: Accepted
// Runtime: 1430 ms
// Memory Usage: 699.9 MB

class Solution {
public:
    int binarySearch(vector<int>matrix,int target,int low,int high)
    {
        while(low<=high)
        {
            int  mid=low+(high-low)/2;
            
            if(matrix[mid]==target)return mid;
            
            if(matrix[mid]<target)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return -1;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        // finding the row in which it lies
        
        int n=matrix.size();
        int row=-1;
        int col=-1;
        int m=matrix[0].size();
        
        for(int i=0;i<n;i++)
        {
            if(matrix[i][0]==target || matrix[i][m-1]==target)return true;
            
            if(matrix[i][0]<target && matrix[i][m-1]>target)
            {

                
                if(binarySearch(matrix[i],target,0,m-1)!=-1)return true;
            }
        }
        return false;
    }
};

int main()
{
    
    return 0;
}