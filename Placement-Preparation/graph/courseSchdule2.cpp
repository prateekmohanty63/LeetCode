#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<stack>
using namespace std;


// T(N)=O(V+E) + O(V+E) + O(V) = O(V+E)
// S(N)=O(V)
class Solution {
public:
   
   bool isCyclic(int start,unordered_map<int,vector<int>>&adj,vector<int>&vis)
   {
       if(vis[start]==1)return true;

       if(vis[start]==0)
       {
           vis[start]=1;
           for(auto it:adj[start])
           {
               if(isCyclic(it,adj,vis)==true)return true;
           }
       }
       vis[start]=2;
       return false;
   }

 

   void topologicalSort(int start,unordered_map<int,vector<int>>&adj,vector<int>&vis,stack<int>&stk)
   {  
	     vis[start]=1;
	     
	     for(auto it:adj[start])
	     {
	         if(vis[it]==0)
	         {
	             topologicalSort(it,adj,vis,stk);
	         }
	     }
	     
	     stk.push(start);
   }

    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        
        unordered_map<int,vector<int>>adj;
        stack<int>stk;
        int n=pre.size();
        vector<int>res;

        for(int i=0;i<n;i++)
        {
            adj[pre[i][0]].push_back(pre[i][1]);
        }
        
        vector<int>vis(numCourses,0);

       for(int i=0;i<numCourses;i++)
       {
           if(vis[i]==0 && isCyclic(i,adj,vis))return {};
       }

        vector<int>vis1(numCourses,0);

       for(int i=0;i<numCourses;i++)
       {
           if(vis1[i]==0)
           {
               topologicalSort(i,adj,vis1,stk);
           }
       }
       while(!stk.empty())
       {
           res.push_back(stk.top());
           stk.pop();
       }
       reverse(res.begin(),res.end());
       return res;
    }
};

int main()
{
    
    return 0;
}