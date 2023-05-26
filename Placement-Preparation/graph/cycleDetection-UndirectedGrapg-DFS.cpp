#include<iostream>
#include<vector>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    bool detect(int src,int parent,vector<int>adj[],int vis[])
    {
       // base case
       vis[src]=1;
       
       for(auto it:adj[src])
       {
           if(vis[it]==0)
           {
               if(detect(it,src,adj,vis)==true)return true;
           }
           else if(vis[it]==1 && it!=parent)
           {
               return true;
           }
       }
       return false;
    }
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        int vis[V]={0};
         
        for(int i=0;i<V;i++){
           if(vis[i]==0 && detect(i,-1,adj,vis))return true;
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends

int main()
{
    
    return 0;
}