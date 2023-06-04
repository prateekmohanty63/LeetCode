#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;


// BFS

class Solution {
public:
 
    bool isCyclic(int start,unordered_map<int,bool>&dfsVis,unordered_map<int,vector<int>>&adj,unordered_map<int,bool>&vis)
   {
         vis[start]=true;
         dfsVis[start]=true;

         for(auto it:adj[start])
         {
             // if node not yet visited 
             if(vis.find(it)==vis.end())
             {
                 if(isCyclic(it,dfsVis,adj,vis))return true;
             }
             else{
                 if(dfsVis[it]==true)return true;
             }
         }
         dfsVis[start]=false;

         return false;
   }

    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        
        vector<int>res;
        
        vector<int>indegree(numCourses,0);

        unordered_map<int,vector<int>>adj;
        for(int i=0;i<pre.size();i++)
        {
            adj[pre[i][0]].push_back(pre[i][1]);
        }

        unordered_map<int,bool>vis,dfsVis;

        for(int i=0;i<numCourses;i++)
        {
            if(vis.find(i)==vis.end())
            {
                if(isCyclic(i,dfsVis,adj,vis)==true)return {};
            }
        }

    // Topological sort using BFS (Kahn's algorithm)
       // calculating in-degree
        for(auto it:adj)
        {
            for(int i=0;i<it.second.size();i++)
            {
                indegree[it.second[i]]++;
            }
        }

        // take a queue
        // push all elements with in-degree 0
        queue<int>q;

        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i]==0)q.push(i);
        }
        
        while(!q.empty())
        {
            int fr=q.front();
            q.pop();
            res.push_back(fr);

            // push the element into result vector
            for(auto it:adj[fr])
            {
                indegree[it]--;

                if(indegree[it]==0)q.push(it);
            }
        }

       reverse(res.begin(),res.end());
        return res;
    }
};


// DFS 

// } Driver Code Ends
class Solution
{
	public:
	stack<int>stk;
	void dfs(int start,int V,vector<int>adj[],vector<int>&vis)
	{
	     
	     vis[start]=1;
	     
	     for(auto it:adj[start])
	     {
	         if(vis[it]==0)
	         {
	             dfs(it,V,adj,vis);
	         }
	     }
	     
	     stk.push(start);
	     
	}
	
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int>res;
	    
	    vector<int>vis(V,0);
	    
	    for(int i=0;i<V;i++)
	    {
	        if(vis[i]==0)
	        {
	            dfs(i,V,adj,vis);
	        }
	    }
	    
	    while(!stk.empty())
	    {
	        res.push_back(stk.top());
	        stk.pop();
	    }
	   return res;
	   
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends

int main()
{
    
    return 0;
}