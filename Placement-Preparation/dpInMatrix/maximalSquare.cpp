#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

// TLE 
// 75/78

class Solution {
public:
   
   bool isSquareOne(vector<vector<char>>&matrix,int startX,int startY,int endX,int endY)
   {
        for(int i=startX;i<=endX;i++)
        {
            for(int j=startY;j<=endY;j++)
            {
                if(matrix[i][j]!='1')return false;
            }
        }
        return true;
   }

   int largestSquare(vector<vector<char>>&matrix,int x,int y,vector<vector<int>>&vis)
   {
       int n=matrix.size();
       int m=matrix[0].size();
         // base case
         if(x<0 || x>=n)return 0;

         if(y<0 || y>=m)return 0;

         if(vis[x][y]!=-1)return vis[x][y];

        int startX=x;
        int startY=y;

        int tempX=startX;
        int tempY=startY;

        int maxArea=INT_MIN;

        while(tempY<m && tempX<n && matrix[startX][tempY]=='1' && matrix[tempX][startY]=='1')
        {
           
            if(isSquareOne(matrix,startX,startY,tempX,tempY))
            {
                int area=(tempX-startX+1)*(tempY-startY+1);
                maxArea=max(maxArea,area);
            }
             tempY++;
            tempX++;

        }

        int front=max(maxArea,largestSquare(matrix,x,y+1,vis));
        int down=max(maxArea,largestSquare(matrix,x+1,y,vis));
        int diag=max(maxArea,largestSquare(matrix,x+1,y+1,vis));
     
      return vis[x][y]=max({front,down,diag});
         
   }

    int maximalSquare(vector<vector<char>>& matrix) {

       
        
        int n=matrix.size();
        int m=matrix[0].size();

         if(n==1 && m==1)
        {
            if(matrix[0][0]=='1')return 1;

            return 0;
        }

        int maxArea=INT_MIN;
        vector<vector<int>>vis(n+1,vector<int>(m+1,-1));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='1')
                {
                    int area=largestSquare(matrix,i,j,vis);
                   cout<<area<<endl;
                   maxArea=max(maxArea,area);
                }
            }
        }

        if(maxArea==INT_MIN)return 0;
        return maxArea;
    }
};

int main()
{
    
    return 0;
}