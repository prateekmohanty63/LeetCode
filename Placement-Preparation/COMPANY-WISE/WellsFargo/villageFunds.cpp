#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>

using namespace std;


// cycle detection

bool isCyclic(unordered_map<int,vector<int>>&adj,int source,int parent,vector<int>&vis)
{
     vis[source]=true;

     for(auto it:adj[source])
     {
         if(vis[it]==0)
         {
             if(isCyclic(adj,it,source,vis))return true;
         }
         else{
            if(it!=parent)return true;
         }
     }
     return false;
}


// T(N)=O(N^3)

vector<int>paths(5,0);

int noPaths(int source,int destination,unordered_map<int,vector<int>>&adj)
{
    queue<int>q;
    q.push(source);
    int count=0;
    unordered_map<int,bool>vis;
    vis[source]=true;

    while(!q.empty())
    {
        int tp=q.front();
        q.pop();
        for(auto it:adj[tp])
        {
            if(it==destination)count++;
            if(vis.find(it)==vis.end())
            {
                vis[it]=true;
                q.push(it);

            }
        }

    }

    return count;

}

void solve1(int source, unordered_map<int,vector<int>>&adj)
{
     queue<int>q;
     
     unordered_map<int,bool>vis;

     q.push(source);

     while(!q.empty())
     {
        int tp=q.front();
        paths[tp]++;
        q.pop();

        for(auto it:adj[tp])
        {
           // paths[it]++;

            if(vis.find(it)==vis.end())
            {
                vis[it]=true;
                q.push(it);
            }
        }
     }
}

int main()
{
    unordered_map<int,vector<int>>adj;
    int n=4;
    adj[0]={1,3};
    adj[1]={0,2};
    adj[2]={1,3};
    adj[3]={0,2,4};
    adj[4]={3};

    vector<int>vis(n+1,0);

    cout<<isCyclic(adj,0,-1,vis);

    return 0;
}