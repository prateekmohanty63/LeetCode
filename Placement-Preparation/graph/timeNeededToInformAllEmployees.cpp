#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<climits>
using namespace std;


// T(N)=O(V*(log(V)+E*log(V)))+O(V)
// T(N)=v*(log(v)+E*log(v))
// T(N)=v*log(v)*(1+E)
// T(N)=v*log(v)*v
// T(N)=O(V^2)
class Solution {
public:
    
    int dijk(int n,int headId,unordered_map<int,vector<pair<int,int>>>&adj)
    {
        // distance matrix
        vector<int>dist(n,INT_MAX);

        // mark the source as 0
        dist[headId]=0;

        // visited set
        vector<int>vis(n,-1);
        vis[headId]=1;

        // priority queue (min heap)
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;

        // push the source into queue
        q.push({0,headId});

        // BFS
        while(!q.empty())                // O(V)
        {
            pair<int,int>fr=q.top();
            q.pop();                    // O(logV)

            int parentNode=fr.second;
            int currCost=fr.first;

            // mark visited
            vis[parentNode]=1;

            for(auto it:adj[parentNode])          // O(E)
            {
                int childNode=it.first;
                int cost=it.second;

                if(vis[childNode]==-1 && dist[childNode]>currCost+cost)
                {
                    dist[childNode]=currCost+cost;
                    q.push({dist[childNode],childNode});    // O(logv)
                }
            }
        }
        int maxTime=INT_MIN;

        for(auto it:dist){
          //  cout<<it<<" ";
        maxTime=max(maxTime,it);
        }

        return maxTime;
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        // building the ajdancency matrix
        unordered_map<int,vector<pair<int,int>>>adj;

        int m=manager.size();

        for(int i=0;i<m;i++)
        {
             int manage=manager[i];
             if(manage!=-1){
              adj[manage].push_back({i,informTime[manage]});
             }
        }

        for(auto it:adj)
        {
            cout<<it.first<<endl;
            vector<pair<int,int>>pr=it.second;
            // for(int i=0;i<pr.size();i++)
            // cout<<pr[i].first<<" "<<pr[i].second<<endl;
        }
       
       int res=dijk(n,headID,adj);
        return res;
    }
};

int main()
{
    
    return 0;
}