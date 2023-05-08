#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        
        int sum=0;
        int n=mat.size();
        int m=mat[0].size();

        for(int i=0;i<n;i++)
        {
            sum+=mat[i][i];
        }

        for(int i=0;i<n;i++)
        {
            sum+=mat[i][n-1-i];
        }

        if(n%2==1)
        {
            sum-=mat[n/2][n/2];
        }

        return sum;
    }
};

int main()
{
    
    return 0;
}
