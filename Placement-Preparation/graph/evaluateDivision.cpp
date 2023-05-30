#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;

// correct solution 
// T(n)=O(N*(V+E))
// S(N)=O(N*(V+E))
class Solution {
public:

  double ans;

  bool dfs(string src,string dest,unordered_map<string,vector<pair<string,double>>>&adj,double val,unordered_map<string,bool>&vis)
  {
      // if source is not present in the adj list we return false
      if(adj.find(src)==adj.end())return false;
       // base case
       if(src==dest){
           ans=val;
           return true;
       }

        vis[src]=true;
        bool tempAns=false;

        for(int i=0;i<adj[src].size();i++)
        {
             string node=adj[src][i].first;
             double cost=adj[src][i].second;

             if(vis.find(node)==vis.end())
             {
                  tempAns=dfs(node,dest,adj,val*cost,vis);
                  if(tempAns)break;
             }
        }
       
        return tempAns;
  }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        int m=queries.size();
        vector<double>res;
        
        // building the adjacenecy matrix
        unordered_map<string,vector<pair<string,double>>>adj;
        for(int i=0;i<equations.size();i++)
        {
            pair<string,double>pr;
            pr.first=equations[i][1];
            pr.second=values[i];
           adj[equations[i][0]].push_back(pr);

           pair<string,double>pr1;
           pr1.first=equations[i][0];
           pr1.second=1/(double)values[i];
           adj[equations[i][1]].push_back(pr1);
        }

        for(int i=0;i<m;i++)
        {
            unordered_map<string,bool>vis;
            bool pathPresent=dfs(queries[i][0],queries[i][1],adj,1,vis);
            cout<<pathPresent<<" ";
            if(!pathPresent)res.push_back(-1);

            else 
            res.push_back(ans);
        }

        return res;
    }
};

// giving error for 1 test case (dijkstra algorithm)
class Solution {
public:
    
    unordered_map<string,double> dijkstra(string src,int n,unordered_map<string,bool>&mp,unordered_map<string,vector<pair<string,double>>>&adj)
    {
        unordered_map<string,double>dist;
        for(auto it:mp)dist[it.first]=99999999999999;
      

        // mark the src node as 0 distance
        dist[src]=1.0000000;

        // visited map
        unordered_map<string,bool>vis;
        
        // making a priority queue 
        priority_queue<pair<double,string>,vector<pair<double,string>>,greater<pair<double,string>>>pr;

        // push the source node and its distance to the priority queue
        pr.push(make_pair(1.0000000,src));

        while(!pr.empty()){
            pair<double,string>p=pr.top();
            pr.pop();
           string parent=p.second;
           vis[parent]=true;

           for(int i=0;i<adj[parent].size();i++)
           {
               string node=adj[parent][i].first;
               double cost=adj[parent][i].second;

               if(vis.find(node)==vis.end() && dist[node]>dist[parent]*cost)
               {
                   dist[node]=dist[parent]*cost;
                   pr.push(make_pair(dist[node],node));
               }
           }

        }
        return dist;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
       // making the adjacency matrix

       unordered_map<string,vector<pair<string,double>>>adj;
       unordered_map<string,bool>nodes;
       unordered_map<string,unordered_map<string,double>>distmatrix;


       int n=equations.size();
       int m=queries.size();
       vector<double>vec;

       for(int i=0;i<n;i++)
       {
           nodes[equations[i][0]]=true;
           nodes[equations[i][1]]=true;

           pair<string,double>pr;
           pr.first=equations[i][1];
           pr.second=values[i];
           adj[equations[i][0]].push_back(pr);

           pair<string,double>pr1;
           pr1.first=equations[i][0];
           pr1.second=1/values[i];
           adj[equations[i][1]].push_back(pr1);
       }
       int r=nodes.size();

       for(auto it:nodes){
           unordered_map<string,double>mp=dijkstra(it.first,r,nodes,adj);
           distmatrix[it.first]=mp;
       }

       for(int i=0;i<m;i++)
       {
           unordered_map<string,double>mp=distmatrix[queries[i][0]];
           cout<<mp[queries[i][1]]<<" ";
          
           if(mp[queries[i][1]]==99999999999999 || mp[queries[i][1]]==0.0000000)
           {
               
               vec.push_back(-1.00000);
           }
           else{
               vec.push_back(mp[queries[i][1]]);
           }
       }
       return vec;
    }
};

int main()
{
    
    return 0;
}