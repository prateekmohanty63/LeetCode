#include<iostream>
#include<vector>
#include<queue>
using namespace std;


// T(N)=O(N)+O(2*E)
// S(N)=O(3N) + O(N)

// } Driver Code Ends
class Solution {
  public:
    
    
  
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>res;
        int vis[V]={0};
        
        vis[0]=1;
        
        queue<int>q;
        q.push(0);
        
        while(!q.empty())
        {
            int ver=q.front();
            q.pop();
            res.push_back(ver);
            
            for(auto it:adj[ver])
            {
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
            
        }
        
        
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

int main()
{
    
    return 0;
}