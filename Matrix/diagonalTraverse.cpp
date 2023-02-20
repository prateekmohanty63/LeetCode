#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        
        int n=mat.size();
        int m=mat[0].size();
        vector<int>res;

        if(n==0 || m==0)return res;

        int i=0,j=0;
        bool up=true;

        while(i<n && j<m)
        {
           
            if(up)
            {
                while(i>0 && j<m-1)
                {
                    res.push_back(mat[i][j]);
                    i--;
                    j++;
                }
                res.push_back(mat[i][j]);

                if(j==m-1)
                {
                   i++;
                }
                else{
                    j++;
                }
            }
            else{
               
               while(i<n-1 && j>0)
               {
                   res.push_back(mat[i][j]);
                   i++;
                   j--;
               }
                res.push_back(mat[i][j]);
               

               if(i==n-1)
               {
                   j++;
               }
               else{
                  i++;
               }
            }
            up=!up;
        }

    return res;
    }
};

int main()
{
    
    return 0;
}