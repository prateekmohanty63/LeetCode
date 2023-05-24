#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
   
   void dfs(vector<vector<int>>&img,int sr,int sc,int &val,int &color,vector<vector<int>>&vis)
   {
       int n=img.size();
       int m=img[0].size();

       if(sr<0 || sr>=n)return ;

       if(sc<0 || sc>=m)return ;

       vis[sr][sc]=1;
       

       // if(img[sr][sc]!=color)return ;

       if(sr+1<n && vis[sr+1][sc]==-1 && img[sr+1][sc]==val)
       {
           img[sr+1][sc]=color;
           dfs(img,sr+1,sc,val,color,vis);
       }
       if(sr-1>=0 && vis[sr-1][sc]==-1 && img[sr-1][sc]==val)
       {
           img[sr-1][sc]=color;
           dfs(img,sr-1,sc,val,color,vis);
       }
       if(sc+1<m && vis[sr][sc+1]==-1 && img[sr][sc+1]==val)
       {
           img[sr][sc+1]=color;
           dfs(img,sr,sc+1,val,color,vis);
       }
       if(sc-1>=0 && vis[sr][sc-1]==-1 && img[sr][sc-1]==val)
       {
           img[sr][sc-1]=color;
           dfs(img,sr,sc-1,val,color,vis);
       }


   }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        //vector<vector<int>>res=img;

        int n=image.size();
        int m=image[0].size();
        vector<vector<int>>vis(n,vector<int>(m,-1));
       
        dfs(image,sr,sc,image[sr][sc],color,vis);
         image[sr][sc]=color;

        return image;
        
    }
};

int main()
{
    
    return 0;
}