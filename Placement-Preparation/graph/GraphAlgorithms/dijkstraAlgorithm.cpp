#include<iostream>
#include<queue>
#include<vector>
#include<climits>

using namespace std;

// USING SET 

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	vector<int> dijk(int V,vector<vector<int>> adj[],int S)
	{
	    // distance matrix
	    vector<int>dist(V,INT_MAX);
	    
	    // marking source at 0 distance
	    dist[S]=0;
	    
	    // taking the set of pairs
	    set<pair<int,int>>st;
	    
	    st.insert(make_pair(0,S));
	    
	    while(!st.empty())
	    {
	        auto &it=*st.begin();
	        
	        int topNode=it.second;
	        int d=it.first;
	        
	        st.erase(it);
	        
	        for(auto ele:adj[topNode])
	        {
	            int currNode=ele[0];
	            int cost=ele[1];
	            
	            if(dist[currNode]>dist[topNode]+cost)
	            {
	                if(dist[currNode]!=INT_MAX)
	                {
	                    // erase the greater distnace pair in the set
	                    st.erase(make_pair(dist[currNode],currNode));
	                }
	                
	                dist[currNode]=dist[topNode]+cost;
	                st.insert(make_pair(dist[currNode],currNode));
	            }
	        }
	        
	        
	    }
	    return dist;
	}
	
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int>vec=dijk(V,adj,S);
        
        return vec;
	      
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// USING PRIORITY QUEUE


// } Driver Code Ends

// } Driver Code Ends
class Solution
{
	public:
	
	vector<int> dijk(int V,vector<vector<int>>adj[],int S)
	{
	    // distance matrix
	    vector<int>dist(V,INT_MAX);
	    
	    // mark the distance to source as 0
	    dist[S]=0;
	    
	    // visited array
	    vector<int>vis(V,0);
	    
	    // push the source and its distance to the priority queue 
	    priority_queue<pair<int, int> ,vector<pair<int, int> >,greater<pair<int,int> >>q;
	    
	    q.push(make_pair(0,S));
	    
	    while(!q.empty())
	    {
	        int parentNode=q.top().second;
	        int distance=q.top().first;
	        vis[parentNode]=1;
	        q.pop();
	        
	        for(auto it:adj[parentNode])
	        {
	            int childNode=it[0];
	            int cost=it[1];
	            
	            if(vis[childNode]==0 && dist[childNode]>distance+cost)
	            {
	                dist[childNode]=distance+cost;
	                q.push(make_pair(dist[childNode],childNode));
	            }
	        }
	    }
	    return dist;
	}
	
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        
        // applying the dijkstra algorithm we get
        
        
        
        vector<int>vec=dijk(V,adj,S);
        
        return vec;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends