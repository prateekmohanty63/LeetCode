#include<iostream>
#include<vector>
using namespace std;


// Runtime: 47 ms, faster than 19.78% of C++ online submissions for Course Schedule.
// Memory Usage: 14.3 MB, less than 38.60% of C++ online submissions for Course Schedule.

class Solution {
public:
    
   bool iscycle(vector<int> adj[],vector<int> &vis,int id){
        if(vis[id]==1)
            return true;
        if(vis[id]==0){
            vis[id]=1;
            for(auto edge : adj[id]){
                if(iscycle(adj,vis,edge))
                    return true;
            }
        }
        vis[id] = 2;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        for(auto edge : pre)
            adj[edge[1]].push_back(edge[0]);
        vector<int> vis(n,0);
        
        for(int i=0;i<n;i++){
            if(iscycle(adj,vis,i))
                return false;
        }
        return true;
    }
};


// gives TLE
class Solution {
public:
    
    bool isCyclic(vector<vector<int>>&adj,vector<int>&visited,int curr)
    {
        if(visited[curr]==2)return true;
        
        visited[curr]=2;
        
        for(int i=0;i<adj[curr].size();i++)
        {
            if(visited[adj[curr][i]!=1])
                if(isCyclic(adj,visited,adj[curr][i]))return true;
        }
        visited[curr]=1;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n=prerequisites.size();
        vector<vector<int>>adj(numCourses);
        
        //  making an adjancey list
        for(int i=0;i<n;i++)
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        vector<int>visited(numCourses,0);
        
        for(int i=0;i<numCourses;i++)
        {
            if(visited[i]==0)
                if(isCyclic(adj,visited,i))return false;
        }
        return true;
    }
};

int main()
{
    
    return 0;
}