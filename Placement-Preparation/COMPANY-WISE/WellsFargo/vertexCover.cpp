//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;



// memoized

class Solution{
    public:
        int minSize=INT_MAX;
        bool isVertexCover(int noEdges,unordered_map<int,vector<int>>&adj,map<pair<int,int>,bool>&mp,vector<int>&vec)
        {
            int count=0;
            
            for(auto it:vec)
            {
                if(adj.find(it)!=adj.end())
                count+=adj[it].size();
            }
            for(int i=0;i<vec.size();i++)
            {
                  pair<int,int>p;
                  p.first=vec[i];
                  
                for(int j=i+1;j<vec.size();j++)
                {
                  
                    p.second=vec[j];
                    
                    if(mp.find(p)!=mp.end())count--;
                }
            }
            
            return count==noEdges;
        }
        
        long long solve(vector<int>&vec,int ind,vector<int>&cover,int &noEdges,unordered_map<int,vector<int>>&adj,map<pair<int,int>,bool>&mp,vector<vector<long long>>&dp,int mask)
        {
            int n=vec.size();
            
              if(isVertexCover(noEdges,adj,mp,cover))
              {
                 int a=cover.size();
                 return a;
               }
            
            
             if(ind>=n)return INT_MAX;
             
             if(dp[ind][mask]!=-1)return dp[ind][mask];
             
            
             
            long long notTaken=solve(vec,ind+1,cover,noEdges,adj,mp,dp,mask);
             
             cover.push_back(vec[ind]);
             int newMask=mask|vec[ind];
             long long taken=solve(vec,ind+1,cover,noEdges,adj,mp,dp,newMask);
             cover.pop_back();
             
             return dp[ind][mask]=min(notTaken,taken);
             
             
        }
        int vertexCover(int n, vector<pair<int, int>> &edges) {
                // code here
                
                // building the adjacency matrix
                
                unordered_map<int,vector<int>>adj;
                map<pair<int,int>,bool>mp;
                
                for(int i=0;i<edges.size();i++)
                {
                    adj[edges[i].first].push_back(edges[i].second);
                    adj[edges[i].second].push_back(edges[i].first);
                    
                    pair<int,int>p;
                    p.first=edges[i].first;
                    p.second=edges[i].second;
                    mp[p]=true;
                    
                    p.first=edges[i].second;
                    p.second=edges[i].first;
                    mp[p]=true;
                }
                
                int noEdges=edges.size();
                
                vector<int>vec;
                
                vector<vector<long long>>dp(n,vector<long long>((1<<32)+1,-1));
                
                for(int i=1;i<=n;i++)vec.push_back(i);
                
                vector<int>cover;
                long long res=solve(vec,0,cover,noEdges,adj,mp,dp,0);
                
                return res;
                
                
        }
};

// } Driver Code Ends
//User function Template for C++


// TLE 

class Solution{
    public:
        int minSize=INT_MAX;
        bool isVertexCover(int noEdges,unordered_map<int,vector<int>>&adj,map<pair<int,int>,bool>&mp,vector<int>&vec)
        {
            int count=0;
            
            for(auto it:vec)
            {
                if(adj.find(it)!=adj.end())
                count+=adj[it].size();
            }
            for(int i=0;i<vec.size();i++)
            {
                  pair<int,int>p;
                  p.first=vec[i];
                  
                for(int j=i+1;j<vec.size();j++)
                {
                  
                    p.second=vec[j];
                    
                    if(mp.find(p)!=mp.end())count--;
                }
            }
            
            return count==noEdges;
        }
        
        void solve(vector<int>&vec,int ind,vector<int>&cover,int &noEdges,unordered_map<int,vector<int>>&adj,map<pair<int,int>,bool>&mp)
        {
            int n=vec.size();
            
             if(isVertexCover(noEdges,adj,mp,cover))
             {
                 int a=cover.size();
                 minSize=min(minSize,a);
             }
            
             if(ind>=n)return ;
             
            
             
             solve(vec,ind+1,cover,noEdges,adj,mp);
             
             cover.push_back(vec[ind]);
             solve(vec,ind+1,cover,noEdges,adj,mp);
             cover.pop_back();
        }
        int vertexCover(int n, vector<pair<int, int>> &edges) {
                // code here
                
                // building the adjacency matrix
                
                unordered_map<int,vector<int>>adj;
                map<pair<int,int>,bool>mp;
                
                for(int i=0;i<edges.size();i++)
                {
                    adj[edges[i].first].push_back(edges[i].second);
                    adj[edges[i].second].push_back(edges[i].first);
                    
                    pair<int,int>p;
                    p.first=edges[i].first;
                    p.second=edges[i].second;
                    mp[p]=true;
                    
                    p.first=edges[i].second;
                    p.second=edges[i].first;
                    mp[p]=true;
                }
                
                int noEdges=edges.size();
                
                vector<int>vec;
                
                for(int i=1;i<=n;i++)vec.push_back(i);
                
                vector<int>cover;
                solve(vec,0,cover,noEdges,adj,mp);
                
                return minSize;
                
                
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>> edges;
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            edges.push_back({a,b});
        }
        Solution s;
        cout<<s.vertexCover(n,edges)<<endl;
    }
    return 0;
}
// } Driver Code Ends