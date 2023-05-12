#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n=matrix.size();
        int m=matrix[0].size();

        int start=0;
        int end=matrix[0].size()-1;
        
        while(start<n && end>=0)
        {
            if(matrix[start][end]==target)return true;

            if(target>matrix[start][m-1])start++;

            else{
                end--;
            }
        }
         
         return false;
    }
};


// T(n)=O(nlogm)

class Solution {
public:
   
   int binSearch(vector<int>&vec,int target)
   {
       int start=0;
       int end=vec.size()-1;

       while(start<=end)
       {
           int mid=start+(end-start)/2;

           if(vec[mid]==target)return mid;

           if(target>vec[mid])start=mid+1;

           else end=mid-1;
       }
       return -1;
   }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();

        for(int i=0;i<n;i++)
        {
            if(matrix[i][0]==target)return true;

            if(matrix[i][m-1]==target)return true;

            else if(target>matrix[i][0] && target<matrix[i][m-1])
            {
                int ind=binSearch(matrix[i],target);
                if(ind!=-1)return ind;
            }
        }
        return false;
    }
};

int main()
{
    
    return 0;
}