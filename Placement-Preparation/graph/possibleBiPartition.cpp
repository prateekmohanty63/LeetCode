#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
  

   bool isPossible(unordered_map<int,vector<int>>&adj,int n,int start,vector<int>&color,vector<int>&vis)
   {
       // queue
       queue<int>q;
       q.push(start);
       vis[start]=1;
       color[start]=1;

       while(!q.empty())
       {
            int parentNode=q.front();
            int parentColor=color[parentNode];
            q.pop();

            for(auto it:adj[parentNode])
            {
                int childNode=it;
                for(auto itr:adj[childNode])
                {
                    if(parentColor==1){
                    if(color[itr]==0)
                    {
                        return false;
                        
                    }
                    }
                    else{
                        if(color[itr]==1)return false;
                    }
                }
                if(parentColor==1)
                color[childNode]=0;
                else color[childNode]=1;

                if(vis[it]==-1)
                {
                    vis[it]=0;
                    q.push(it);
                }
                
            }

       }
       return true;
       
   }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        // adjacency matrix
        unordered_map<int,vector<int>>adj;
        vector<int>color(n+1,-1);
        vector<int>vis(n+1,-1);

        for(int i=0;i<dislikes.size();i++)
        {
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }

        for(int i=1;i<=n;i++)
        {
            if(vis[i]==-1)
            {
                if(isPossible(adj,n,i,color,vis)==false)return false;
            }
        }
        for(auto it:color)cout<<it<<" ";
   return true;

    }
};

int main()
{
    
    return 0;
}