//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	void dfs(vector<int>adj[],int node,vector<int>&vis)
	{
	    vis[node]=true;
	    
	    for(auto it:adj[node])
	    {
	        if(vis[it]==0)
	        dfs(adj,it,vis);
	    }
	}
	
	void dfs1(vector<int>adj[],int node,vector<int>&vis,int &c,int &d)
	{
	    vis[node]=true;
	    
	    for(auto it:adj[node])
	    {
	        if(vis[it]==0)
	        {
	            if((it==c && node==d) || (it==d && node==c))continue;
	            
	            dfs1(adj,it,vis,c,d);
	        }
	    }
	}
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        
        int component1=0;
        vector<int>vis(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            {
                component1++;
                dfs(adj,i,vis);
            }
        }
      //  cout<<component1<<" ";
        
        int component2=0;
        vector<int>vis1(V,0);
        for(int i=0;i<V;i++)
        {
            if(vis1[i]==0)
            {
                component2++;
                dfs1(adj,i,vis1,c,d);
            }
        }
      //  cout<<component2<<" ";
        
        return component2>component1;
    }
};

//{ Driver Code Starts.

int main()
{
    
    return 0;
}

// } Driver Code Ends