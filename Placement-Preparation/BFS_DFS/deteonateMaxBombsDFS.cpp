#include<iostream>
#include<vector>
#include<cmath>
#include<climits>
#include<unordered_map>
using namespace std;


class Solution {
public:
    
    bool withinRange(int startx,int starty,int radius,int x,int y)
    {
        double distCenters=(double)sqrt(pow(startx-x,2)+pow(starty-y,2));

        if(distCenters<=radius)return true;

        return false;
    }
    
    void dfs(int start,unordered_map<int,vector<int>>&adj,vector<int>&vis)
    {
         vis[start]=1;

         for(auto it:adj[start])
         {
             if(vis[it]==-1)
             {
                 dfs(it,adj,vis);
             }
         }
    }


    int maximumDetonation(vector<vector<int>>& bombs) {
        
        int n=bombs.size();
        int res=INT_MIN;
      
        unordered_map<int,vector<int>>adj;

       // making the ajdcency matrix
        for(int i=0;i<n;i++)
        {
            int startx=bombs[i][0];
            int starty=bombs[i][1];
            int radius=bombs[i][2];

            for(int j=0;j<n;j++)
            {
                if(withinRange(startx,starty,radius,bombs[j][0],bombs[j][1]))
                {
                    adj[i].push_back(j);
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            vector<int>vis(n,-1);
            dfs(i,adj,vis);
            int count=0;
            for(auto it:vis)count+=(it==1);
            res=max(res,count);

        }

        return res;
    }
};

// DFS 
class Solution {
public:
    
    bool withinRange(int startx,int starty,int radius,int x,int y)
    {
        double distCenters=(double)sqrt(pow(startx-x,2)+pow(starty-y,2));

        if(distCenters<=radius)return true;

        return false;
    }

    void maxDet(int start,vector<vector<int>>&bomb,vector<int>&vis)
    {
        // marking the starting as detonated
        vis[start]=1;

        int n=bomb.size();
        
        int x=bomb[start][0];
        int y=bomb[start][1];
        int r=bomb[start][2];

        for(int i=0;i<n;i++)
        {
            if(vis[i]==-1)
            {
                int currx=bomb[i][0];
                int curry=bomb[i][1];

                if(withinRange(x,y,r,currx,curry)==true)
                {
                    //vis[i]=1;
                   maxDet(i,bomb,vis);
                }
            }
        }

    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        
        int n=bombs.size();
      
        int res=INT_MIN;

        for(int i=0;i<n;i++)
        {
            vector<int>vis(n,-1);
            maxDet(i,bombs,vis);
            int count=0;
            for(auto it:vis)count+=(it==1);

            res=max(res,count);
        } 
       

        return res;
    }
};

int main()
{
    
    return 0;
}