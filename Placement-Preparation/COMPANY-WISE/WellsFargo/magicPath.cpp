// Given a weighted undirected graph, two vertices source and destination are specified.
// There can be multiple paths between source and destination.
//  There is a magician who can perform k magic tricks(k given) in which the trick involves reducing an edge weight to 0. 
// With at most k magic tricks allowed, find the shortest path from source and destination.

#include<iostream>
#include<unordered_map>
#include<vector>
#include<climits>
#include<queue>
#include<algorithm>

using namespace std;

vector<vector<int>>paths;
int minCost=INT_MAX;

void dfs(unordered_map<int,vector<pair<int,int>>>&adj,int source,int destination,vector<int>&weight,vector<int>&vis,int &k)
{
     if(source==destination){
       
       int cost=0;
       sort(weight.begin(),weight.end());
       
       if(weight.size()<=k)minCost=0;
       else{
           int ptr=weight.size()-k-1;
           while(ptr>=0)
           {
            cost+=weight[ptr];
            ptr--;
           }
           minCost=min(minCost,cost);
       }

       paths.push_back(weight);
        return ;
     }

     vis[source]=true;

     for(auto it:adj[source])
     {
         if(vis[it.first]==0)
         {
             weight.push_back(it.second);
             dfs(adj,it.first,destination,weight,vis,k);
             weight.pop_back();
         }
     }
}


vector<int> dijk(unordered_map<int,vector<pair<int,int>>>&adj,int n,int source,int destination,int k)
{
    vector<int>dist(n,INT_MAX);
    dist[source]=0;
    vector<int>vis(n,0);
    
     priority_queue<pair<int, int> ,vector<pair<int, int> >,greater<pair<int,int> >>q;
    q.push({source,0});

    while(!q.empty())
    {
        int parentNode=q.top().first;
        int cost=q.top().second;
        q.pop();
        vis[parentNode]=true;

        for(auto it:adj[parentNode])
        {
            int childNode=it.first;
            int cst=it.second;

            if(vis[childNode]==0 && dist[childNode]>cost+cst)
            {
                 dist[childNode]=cost+cst;
                 q.push({childNode,dist[childNode]});
            }
        }
    }
    return dist;
    
}

int main()
{
    int n,k;
    n=6;
    k=1;

    unordered_map<int,vector<pair<int,int>>>adj;
   
   adj[0]={{1,2},{2,2},{3,4}};
   adj[1]={{0,2},{4,7}};
   adj[2]={{0,2},{3,2}};
   adj[3]={{0,4},{2,2},{4,5}};
   adj[4]={{1,7},{3,5}};

    // vector<int>dist=dijk(adj,n,0,4,k);  

   
    vector<int>vis(n,0);
      vector<int>wei;
     dfs(adj,4,0,wei,vis,k);

    sort(paths.begin(),paths.end());

    n=paths.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<paths[i].size();j++)
        cout<<paths[i][j]<<" ";

        cout<<endl;
    }
    cout<<minCost;
    return 0;
}