#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:
  
  vector<double> solve(int n,unordered_map<int,vector<pair<int,double>>>&adj,int start,int end)
  {
      // distance matrix
      vector<double>dist(n,-1);

      // mark source as probability 1
      dist[start]=1;

      // mark the source at visited
      vector<int>vis(n,-1);
      vis[start]=1;

      // queue for BFS
      priority_queue<pair<double,int>,vector<pair<double,int>>>q;

      // push the source into priority queue
      q.push({1,start});


      // BFS

      while(!q.empty())
      {
          pair<double,int>fr=q.top();
          q.pop();
          int parentNode=fr.second;
          double currProb=fr.first;
          vis[parentNode]=1;

         // cout<<currProb<<" ";
          
         // if(parentNode==end)return currProb;

          for(auto it:adj[parentNode])
          {
              int childNode=it.first;
              double childProb=it.second;

              if(vis[childNode]==-1 && dist[childNode]<currProb*childProb)
              {
                    
                    dist[childNode]=currProb*childProb;
                    q.push({dist[childNode],childNode});
              }
          }

      }
      return dist;
  }

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        // building the adjancency matrix

        unordered_map<int,vector<pair<int,double>>>adj;

        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }

        vector<double>vec=solve(n,adj,start,end);

      //  for(auto it:vec)cout<<it<<" ";

        if(vec[end]==-1)return 0;


        return vec[end];

    
    }
};

int main()
{
    
    return 0;
}