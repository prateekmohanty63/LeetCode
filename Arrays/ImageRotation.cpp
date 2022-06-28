#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Rotate Image.
// Memory Usage: 7 MB, less than 92.54% of C++ online submissions for Rotate Image.

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
         int n = matrix.size();
        
        //first we take transpose of the matrix
        for(int i = 0; i < n; ++i){
            for(int j = i; j < n; ++j){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i = 0; i < n; ++i){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

// Runtime: 12 ms, faster than 9.01% of C++ online submissions for Rotate Image.
// Memory Usage: 7.3 MB, less than 33.06% of C++ online submissions for Rotate Image.

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
         
        int n=matrix.size();
         vector<vector<int>>auxVector(n,vector<int>(n,0));
          int m=0;
        
        for(int i=0;i<n;i++)
        {
            int k=n-1;
          
            for(int j=0;j<n;j++)
            {
                auxVector[i][j]=matrix[k][m];
                k--;
            }
            m++;
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<auxVector[i][j]<<" ";
            
            cout<<endl;
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                matrix[i][j]=auxVector[i][j];
            }
        }
    }
};

int main()
{
    
    return 0;
}