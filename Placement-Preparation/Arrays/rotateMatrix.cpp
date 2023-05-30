#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();

       // taking the transpose of the matrix

       for(int i=0;i<n;i++)
       {
           for(int j=0;j<i;j++)
           {
               swap(matrix[i][j],matrix[j][i]);
           }
       }

       // reversing each row
       for(int i=0;i<n;i++)
       {
           int start=0;
           int end=m-1;

           while(start<=end)
           {
               swap(matrix[i][start],matrix[i][end]);
               start++;
               end--;
           }
       }
    }
};

int main()
{
    
    return 0;
}