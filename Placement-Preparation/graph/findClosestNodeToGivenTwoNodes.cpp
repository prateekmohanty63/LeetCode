#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<climits>

using namespace std;


class Solution {
public:
   typedef pair<int,int> p;
   vector<int> dijk(int &n,unordered_map<int,vector<int>>&adj,int node)
   {
       priority_queue<p,vector<p>,greater<p>>q;
       vector<int>vis(n,0);
       vector<int>dist(n,INT_MAX);
       vis[node]=true;
       q.push({0,node});
       dist[node]=0;

       while(!q.empty())
       {
           int currDist=q.top().first;
           int currNode=q.top().second;
           q.pop();
           vis[currNode]=1;


           for(auto it:adj[currNode])
           {
               int childNode=it;

               if(vis[childNode]==0 && dist[childNode]>currDist+1)
               {
                   dist[childNode]=currDist+1;
                   q.push({dist[childNode],childNode});
               }
           }
       }
       return dist;

   }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        
        // building the adjacency matrix
        int n=edges.size();
        unordered_map<int,vector<int>>adj;

        for(int i=0;i<n;i++)
        {
           if(edges[i]!=-1)adj[i].push_back(edges[i]);
        }

        vector<int>vec1=dijk(n,adj,node1);
        vector<int>vec2=dijk(n,adj,node2);

        int res=INT_MAX;
        int ans;

        for(int i=0;i<vec1.size();i++)
        {
            int a=max(vec1[i],vec2[i]);
            if(a<res)
            {
                ans=i;
                res=a;
            }

        }
        if(res==INT_MAX)return -1;
        return ans;

    }
};

int main()
{
    
    return 0;
}