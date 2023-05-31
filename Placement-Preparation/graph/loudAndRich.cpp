#include<iostream>
#include<unordered_map>
#include<vector>
#include<climits>
#include<queue>

using namespace std;

class Solution {
public:
    
    vector<int> dist(int k,int n,unordered_map<int,vector<int>>&adj)
    {
        // distance matrix
        vector<int>dist(n,INT_MAX);
        vector<int>vis(n,0);

        // mark the source as 0
        dist[k]=0;

        vis[k]=1;
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pr;
        pr.push({0,k});

        while(!pr.empty())
        {
            pair<int,int>p=pr.top();
            pr.pop();
            int topNode=p.second;
            vis[topNode]=1;

            for(auto it:adj[topNode])
            {
                int node=it;
                int cost=1;

                if(vis[node]==0 && dist[node]>dist[topNode]+cost)
                {
                    dist[node]=dist[topNode]+cost;
                    pr.push({dist[node],node});
                }
            }
        }
       return dist;
       
    }
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        
         unordered_map<int,vector<int>>adj;
          int noPeople=quiet.size();
          vector<int>res;

          for(int i=0;i<richer.size();i++)
          {
              adj[richer[i][1]].push_back(richer[i][0]);
          }

        
        vector<int>vec=dist(0,noPeople,adj);
        for(auto it:vec)cout<<it<<" ";

        unordered_map<int,vector<int>>distmatrix;
       
        for(int i=0;i<noPeople;i++)
        {
            vector<int>vec=dist(i,noPeople,adj);
            distmatrix[i]=vec;
        }

        for(int i=0;i<noPeople;i++)
        {
            int minQuiet=INT_MAX;
            int ind=-1;
            vector<int>vec=distmatrix[i];

            for(int j=0;j<vec.size();j++)
            {
                if(vec[j]!=INT_MAX)
                {
                    if(quiet[j]<=minQuiet)
                    {
                        minQuiet=quiet[j];
                        ind=j;
                    }
                }
            }
            res.push_back(ind);

        }

        
    return res;

    }
};


// TLE

class Solution {
public:
    
    bool isReachable(int src,int target,unordered_map<int,vector<int>>&adj,unordered_map<int,bool>&vis)
    {
          if(src==target)return true;

          vis[src]=true;

          for(auto it:adj[src])
          {
              if(vis.find(it)==vis.end())
              {
                  if(isReachable(it,target,adj,vis))return true;
              }
          }

          return false;
    }
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        
         unordered_map<int,vector<int>>adj;
          int noPeople=quiet.size();
          vector<int>res;

          for(int i=0;i<richer.size();i++)
          {
              adj[richer[i][0]].push_back(richer[i][1]);
          }

        
        
        
        
        for(int i=0;i<noPeople;i++)
        {
            int node=i;
            int maxQuiet=INT_MAX;
            int per=-1;

            for(int j=0;j<noPeople;j++)
            {
                 unordered_map<int,bool>vis;
                if(isReachable(j,i,adj,vis))
                {
                    if(quiet[j]<=maxQuiet)
                    {  
                        cout<<i<<" "<<j<<endl;
                        maxQuiet=quiet[j];
                        per=j;
                    }
                }
            }
            res.push_back(per);
        }

        
    return res;

    }
};

int main()
{
    
    return 0;
}