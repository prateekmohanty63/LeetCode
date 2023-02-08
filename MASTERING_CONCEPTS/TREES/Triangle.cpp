#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:
   
   int maxSum(vector<vector<int>>&triangle,int i,int j,vector<vector<int>>&dp)
   {
       // base case

       if(i>=triangle.size())return 0;

       if(j>=triangle[i].size())return 0;

       if(dp[i][j]!=-1)return dp[i][j];

  
       // if we are at index i , we will move to index i of next row or index i+1 of next row

       return dp[i][j]=min(triangle[i][j]+maxSum(triangle,i+1,j,dp),triangle[i][j]+maxSum(triangle,i+1,j+1,dp));


   }
    
    int minimumTotal(vector<vector<int>>& triangle) {

        vector<vector<int>>dp(201,vector<int>(201,-1));
        int res=maxSum(triangle,0,0,dp);
       

        return res;
    }
};

class Solution {
public:
   
   int maxSum(vector<vector<int>>&triangle,int i,int j,unordered_map<string,int>&dp)
   {
       // base case

       if(i>=triangle.size())return 0;

       if(j>=triangle[i].size())return 0;

       string res=to_string(i)+"*"+to_string(j);

       if(dp.find(res)!=dp.end())return dp[res];

       // if we are at index i , we will move to index i of next row or index i+1 of next row

       return dp[res]=min(triangle[i][j]+maxSum(triangle,i+1,j,dp),triangle[i][j]+maxSum(triangle,i+1,j+1,dp));


   }
    
    int minimumTotal(vector<vector<int>>& triangle) {

        unordered_map<string,int>dp; 
        int res=maxSum(triangle,0,0,dp);
       

        return res;
    }
};

int main()
{
    
    return 0;
}