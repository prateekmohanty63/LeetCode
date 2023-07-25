#include<iostream>
using namespace std;

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	static bool cmp(vector<int>&vec1,vector<int>&vec2)
	{
	    return vec1[2]<vec2[2];
	}
	
	  vector<int> parent;
    vector<int> rank;
    
    int find(int i) {
        if(parent[i] != i)
            parent[i] = find(parent[i]);
        
        return parent[i];
    }
    
    void Union(int x, int y) {
        int p_x = find(x);
        int p_y = find(y);
        
        if(p_x != p_y) {
            if(rank[p_x] > rank[p_y]) {
                parent[p_y] = p_x;
            } else if(rank[p_y] > rank[p_x]) {
                parent[p_x] = p_y;
            } else {
                parent[p_x] = p_y;
                rank[p_y]++;
            }
        }
    }
	
	int Kruskal(vector<vector<int>>&vec)
	{
	    int sum=0;
	    
	    for(auto it:vec)
	    {
	        int u=it[0];
	        int v=it[1];
	        int wt=it[2];
	        
	        int parent_u=find(u);
	        int parent_v=find(v);
	        
	        if(parent_u!=parent_v)
	        {
	            Union(u,v);
	            sum+=wt;
	        }
	    }
	    return sum;
	}
	
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        parent.resize(V);
        rank.resize(V,0);
        
        for(int i=0;i<V;i++)
        parent[i]=i;
        
        vector<vector<int>>vec;
        
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                int u=i;
                int v=it[0];
                int wt=it[1];
                
                vec.push_back({u,v,wt});
            }
        }
        
        sort(vec.begin(),vec.end(),cmp);
        
        return Kruskal(vec);
    }
};

//{ Driver Code Starts.



// } Driver Code Ends

int main()
{
    
    return 0;
}