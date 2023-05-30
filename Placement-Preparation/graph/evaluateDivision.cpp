#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;

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
          
           else if(mp[queries[i][1]]==99999999999999 || mp[queries[i][1]]==0.0000000)
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