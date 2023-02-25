#include<iostream>
#include<vector>
using namespace std;


// logic is correct , giving TLE as T(N)=2^n
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