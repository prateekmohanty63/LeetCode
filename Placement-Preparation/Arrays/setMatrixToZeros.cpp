#include<iostream>
#include<vector>
#include<set>
using namespace std;


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();

        set<int>row,col;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
       
       // set the row to 0s 
        for(auto it:row)
        {
            // set the row 
            int rw=it;
            
            if(rw<n){
            for(int i=0;i<m;i++)
            {
                matrix[rw][i]=0;
            }
            }
        }

        // set the col to 0s
        for(auto it:col)
        {
            int cl=it;
            
            if(cl<m){
            for(int i=0;i<n;i++)
            {
                matrix[i][cl]=0;
            }
            }
        }
      
    }
};

int main()
{
    
    return 0;
}