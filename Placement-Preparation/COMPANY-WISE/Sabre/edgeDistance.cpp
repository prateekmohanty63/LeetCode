#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<climits>

using namespace std;

int dijk(int source,int n,unordered_map<int,vector<int>>&adj)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    vector<int>vis(n,0);
    vector<int>dist(n,INT_MAX);

    dist[source]=0;
    q.push({0,source});

    while(!q.empty())
    {
        int currNode=q.top().second;
        int currCost=q.top().first;
        q.pop();
        vis[currNode]=1;

        for(auto it:adj[currNode])
        {
            if(vis[it]==0 && dist[it]>currCost+1)
            {
                dist[it]=currCost+1;
                q.push({dist[it],it});
               // vis[it]=true;
            }
        }
    }
    int res=0;
    for(auto it:dist){

        if(it!=source && it<=2)res++;
        cout<<it<<" ";
    }
    return res;
}

int main()
{
    int n;
    cin>>n;

    vector<vector<int>>vec;

    for(int i=0;i<n;i++)
    {
        int m;
        cin>>m;
        vector<int>v;
        for(int j=0;j<m;j++)
        {
            int b;
            cin>>b;
            v.push_back(b);
        }
        vec.push_back(v);
    }

    unordered_map<int,vector<int>>adj;

    for(int i=0;i<vec.size();i++)
    {
         for(int j=0;j<vec[i].size();j++)
         {
            adj[i].push_back(vec[i][j]);
            adj[vec[i][j]].push_back(i);
         }
    }

    for(auto it:adj)
    {
        cout<<it.first<<"-> ";
        for(auto itr:it.second)cout<<itr<<" ";
        cout<<endl;
    }

    int source;
    cin>>source;
    int res=dijk(source,n,adj);
    cout<<endl;
    cout<<res;


    return 0;
}