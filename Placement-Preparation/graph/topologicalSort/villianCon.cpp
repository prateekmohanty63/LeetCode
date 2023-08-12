#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

class Solution{
public:
    int solve(int N,unordered_map<int,vector<int>>&adj,vector<int>&inDegree)
    {
         queue<int>q;
         int count=0;
         
         for(int i=1;i<=N;i++)
         {
             if(inDegree[i]==0)
             q.push(i);
         }
         
         while(!q.empty())
         {
            int size=q.size();
            
            while(size!=0)
            {
                int node=q.front();
                q.pop();
                size--;
                
                for(auto it:adj[node])
                {
                    inDegree[it]--;
                    if(inDegree[it]==0)q.push(it);
                }
            }
             count++;
         }
         return count;
         
    }
    int minColour(int N, int M, vector<int> mat[]) {
        // code here
        
        unordered_map<int,vector<int>>adj;
        vector<int>inDegree(N+1,0);
        
        for(int i=0;i<M;i++)
        {
            int u=mat[i][0];
            int v=mat[i][1];
            adj[v].push_back(u);
            inDegree[u]++;
        }
        
       
        
        int res=solve(N,adj,inDegree);
        
        return res;
        
        
    }
};
int main()
{
    
    return 0;
}