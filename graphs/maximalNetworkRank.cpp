#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
#include<algorithm>
using namespace std;


class Solution {
public:
   
   int maxConnection(int city1,int city2,unordered_map<int,vector<int>>&adj)
   {
        int totalConnections=0;

        if(adj.find(city1)!=adj.end())
        {
            totalConnections+=adj[city1].size();

            vector<int>vec=adj[city1];

            if(find(vec.begin(),vec.end(),city2)!=vec.end())totalConnections--;
        }

         if(adj.find(city2)!=adj.end())
        {
            totalConnections+=adj[city2].size();

          
        }

        return totalConnections;
   }

    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        // building the adjacency matrix


        unordered_map<int,vector<int>>adj;
       // int n=roads.size();

        for(int i=0;i<roads.size();i++)
        {
             adj[roads[i][0]].push_back(roads[i][1]);
             adj[roads[i][1]].push_back(roads[i][0]);
        }
        
        int res=INT_MIN;

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                res=max(res,maxConnection(i,j,adj));
            }
        }
        
        return res;
    }
};

int main()
{
    
    return 0;
}