#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;


class Solution {
public:
    vector<int> topoSort(unordered_map<int,vector<int>>&adj,vector<int>&inDegree)
    {
        int n=inDegree.size();
        queue<int>q;

        for(int i=0;i<n;i++)
        {
            if(inDegree[i]==0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int tp=q.front();
            q.pop();

            for(auto it:adj[tp])
            {
                if(inDegree[it]>0)
                inDegree[it]--;

                if(inDegree[it]==0)q.push(it);
            }
        }
        return inDegree;
    }
    int longestCycle(vector<int>& edges) {
        
        int n=edges.size();
        vector<int>inDegree(n,0);

        for(int i=0;i<n;i++)
        {
            if(edges[i]!=-1)
            inDegree[edges[i]]++;
        }

        unordered_map<int,vector<int>>adj;

        for(int i=0;i<n;i++)
        {
            if(edges[i]!=-1)
            adj[i].push_back(edges[i]);
        }
        vector<int>indegree=topoSort(adj,inDegree);
        int count=0;

        for(auto it:indegree){
            cout<<it<<" ";
            count+=(it>=1);
        }

        if(count==0)return -1;
        return count;
    }
};

int main()
{
    
    return 0;
}