#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>vec;
        vector<vector<int>>vec1;
      

      // upper half the matrix , including the middle diagonal
       for(int i=0;i<m;i++)
       {
            int start=0;
            int j=i;
            vector<int>v;

            while(start<n && j<m)
            {
                  v.push_back(mat[start][j]);
                  start++;
                  j++;
            }
            vec.push_back(v);
       }
       for(int i=0;i<vec.size();i++)
       {
           vector<int>v=vec[i];
           sort(v.begin(),v.end());
           vec[i]=v;
       }
        int ii=0;
       for(int i=0;i<m;i++)
       {
           int start=0;
           int j=i;
           int jj=0;
           while(start<n && j<m)
           {
               mat[start][j]=vec[ii][jj];
               start++;
               j++;
               jj++;
           }
           ii++;
       }
       // lower half of the matrix
       for(int i=1;i<n;i++)
       {
           int start=i;
           int j=0;
           vector<int>v;
           while(start<n && j<m)
           {
               v.push_back(mat[start][j]);
               start++;
               j++;
           }
           vec1.push_back(v);
       }
       for(int i=0;i<vec1.size();i++)
       {
           vector<int>vec=vec1[i];
           sort(vec.begin(),vec.end());
           vec1[i]=vec;
       }
       ii=0;
       for(int i=1;i<n;i++)
       {
           int start=i;
           int j=0;
           //int ii=0;
           int jj=0;
           while(start<n && j<m)
           {
               mat[start][j]=vec1[ii][jj];
               start++;
               j++;
               jj++;
           }
           ii++;
       }
    
     return mat;
       
    }
};

int main()
{
    
    return 0;
}