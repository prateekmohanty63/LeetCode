
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	typedef pair<int,int> p;
	
	int solve(int V,vector<vector<int>>adj[])
	{
	   priority_queue<p,vector<p>,greater<p>>q;
	   int sum=0;
	   vector<int>vis(V,0);
	   
	   q.push({0,0});
	  
	   while(!q.empty())
	   {
	       int weight=q.top().first;
	       int node=q.top().second;
	       q.pop();
	       
	       // if visited continue
	       if(vis[node]==1)continue;
	       
	       	// mark node as visited
	       vis[node]=1;
	       
	       sum+=weight;
	       

	       
	       for(auto it:adj[node])
	       {
	           int neigh=it[0];
	           int wei=it[1];
	           
	           if(vis[neigh]==0)
	            q.push({wei,neigh});
	           
	           
	       }
	       
	       
	   }
	   return sum;
	   
	   
	}
	
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
       int res=solve(V,adj);
       
       return res;
       
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends

int main()
{
    
    return 0;
}