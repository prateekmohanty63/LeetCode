//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
   void solve(vector<vector<int>>&image,int sr,int sc,int newColor,int currColor)
   {
     //  image[sr][sc]=newColor;
       queue<pair<int,int>>q;
      
       int n=image.size();
       int m=image[0].size();
       
        vector<vector<int>>vis(n,vector<int>(m,0));
        vis[sr][sc]=1;
       
       
       q.push({sr,sc});
       vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
       
       while(!q.empty())
       {
           int x=q.front().first;
           int y=q.front().second;
           q.pop();
           image[x][y]=newColor;
          
           
           for(int i=0;i<4;i++)
           {
               int newX=x+dir[i][0];
               int newY=y+dir[i][1];
               
               if(newX>=0 && newX<n && newY>=0 && newY<m && vis[newX][newY]==0 && image[newX][newY]==currColor)
               {
                    vis[newX][newY]=1;
                   q.push({newX,newY});
               }
           }
       }
   }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        
        int currColor=image[sr][sc];
        
        solve(image,sr,sc,newColor,currColor);
        
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	
}
// } Driver Code Ends