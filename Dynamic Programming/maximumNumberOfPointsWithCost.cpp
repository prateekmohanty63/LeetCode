#include<iostream>
#include<vector>
using namespace std;


// TLE , passed 57 test cases
class Solution {
public:
   
   long long maxPnt(vector<vector<int>>&points,int i,int prev,int n,int m)
   {
       // base case

       if(i>=n)return 0;

       long long maxim=0;

       for(int j=0;j<m;j++)
       {
           if(i!=0 && prev!=-1)
           {
               maxim=max(maxim,points[i][j]-abs(j-prev)+maxPnt(points,i+1,j,n,m));
           }
           else{
               maxim=max(maxim,points[i][j]+maxPnt(points,i+1,j,n,m));
           }
       }
       return maxim;
   }

    long long maxPoints(vector<vector<int>>& points) {
        
        int n=points.size();
        int m=points[0].size();
        long long res=maxPnt(points,0,-1,n,m);

        return res;
    }
};


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