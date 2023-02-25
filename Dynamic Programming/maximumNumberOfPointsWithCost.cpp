#include<iostream>
#include<vector>
using namespace std;


// giving TLE after 140 cases

class Solution {
public:
   
   long long maxPoint(vector<vector<int>>&points,int i,int j,int prev,int n,int m,vector<vector<vector<int>>>&dp)
   {
       // base case
      
      if(i>=n)return 0;

      if(dp[i][j][prev+1]!=-1)return dp[i][j][prev+1];

      if(j>=m)return maxPoint(points,i+1,0,prev,n,m,dp);
      
      if(prev!=-1 && i!=0)
      {
          return dp[i][j][prev+1]=max((points[i][j]-(abs(j-prev)))+maxPoint(points,i+1,0,j,n,m,dp),maxPoint(points,i,j+1,prev,n,m,dp));
      }
      else{
          return dp[i][j][prev+1]=max(points[i][j]+maxPoint(points,i+1,0,j,n,m,dp),maxPoint(points,i,j+1,prev,n,m,dp));
      }
   }

    long long maxPoints(vector<vector<int>>& points) {
        
         int n=points.size();
        int m=points[0].size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(m+1,-1)));
       
        long long res=maxPoint(points,0,0,-1,n,m,dp);

        return res;
    }
};


// logic is correct , giving TLE as T(N)=2^n , 50 test cases
class Solution {
public:
   
   long long maxPoint(vector<vector<int>>&points,int i,int j,int prev,int n,int m)
   {
       // base case
      
      if(i>=n)return 0;

      if(j>=m)return maxPoint(points,i+1,0,prev,n,m);
      
      if(prev!=-1 && i!=0)
      {
          return max((points[i][j]-(abs(j-prev)))+maxPoint(points,i+1,0,j,n,m),maxPoint(points,i,j+1,prev,n,m));
      }
      else{
          return max(points[i][j]+maxPoint(points,i+1,0,j,n,m),maxPoint(points,i,j+1,prev,n,m));
      }
   }

    long long maxPoints(vector<vector<int>>& points) {
        
        int n=points.size();
        int m=points[0].size();
        long long res=maxPoint(points,0,0,-1,n,m);

        return res;
    }
};

int main()
{
    
    return 0;
}