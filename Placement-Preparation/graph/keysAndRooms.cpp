#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
   void dfs(unordered_map<int,vector<int>>&adj,vector<int>&vis,int start)
   {
        vis[start]=1;

        for(auto it:adj[start])
        {
            if(vis[it]==0)
            {
                dfs(adj,vis,it);
            }
        }
   }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n=rooms.size();

        unordered_map<int,vector<int>>adj;

        for(int i=0;i<n;i++)
        {
            adj[i]=rooms[i];
        }
        vector<int>vis(n,0);

        dfs(adj,vis,0);

        for(auto it:vis)
        {
            if(it==0)return false;
        }
        return true;
    }
};

int main()
{
    
    return 0;
}