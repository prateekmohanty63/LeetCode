#include<iostream>
#include<vector>


using namespace std;

class Solution {
public: 
    
    int movedOut=0;
    int movedIn=0;
    

    double solve(int n,int k,int row,int column,vector<vector<vector<double>>>&dp)
    {
        // base case
       
        if(row<0 || row>=n)
        {
           return 0;
        }
        if(column<0 || column>=n)
        {
           return 0;
        }

        else if(row>=0 && row<n && column>=0 && column<n && k==0)
        {
           return 1;
        }

        if(dp[row][column][k]!=-1)return dp[row][column][k];

        vector<vector<int>>dir={{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};
        
        double ans=0;
        for(int i=0;i<8;i++)
        {
            int nextX=row+dir[i][0];
            int nextY=column+ dir[i][1];

            ans+=(double)solve(n,k-1,nextX,nextY,dp);
        }
        return dp[row][column][k]=(double)(ans/(double)8);

    }
    double knightProbability(int n, int k, int row, int column) {
        
        vector<vector<vector<double>>>dp(25,vector<vector<double>>(25,vector<double>(101,-1)));
        double ans=solve(n,k,row,column,dp);

       cout<<ans;

       

        return ans;
    }
};

int main()
{
    
    return 0;
}