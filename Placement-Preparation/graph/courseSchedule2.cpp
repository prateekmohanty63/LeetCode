#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
   
   vector<int>order;
   unordered_map<int,bool>mp;

   bool dfs(int start,unordered_map<int,vector<int>>&adj,vector<int>&vis,int numCourses)
   {
       if(vis[start]==1)return true;

      
      for(int i=0;i<numCourses;i++){
       if(adj.find(i)==adj.end())
       {   
           if(mp.find(i)==mp.end()){
               mp[i]=true;
           order.push_back(i);
           }
           for(auto it:adj)
           {
               vector<int>vec=it.second;
               vector<int>vec1;
               for(int j=0;j<vec.size();j++)
               {
                   if(vec[j]!=i)vec1.push_back(vec[j]);

                   
               }
               adj[it.first]=vec1;
           }
       }
       else if(adj.find(i)!=adj.end() && adj[i].size()==0)
       {
           if(mp.find(i)==mp.end()){
               mp[i]=true;
           order.push_back(i);
           }
           for(auto it:adj)
           {
               vector<int>vec=it.second;
               vector<int>vec1;
               for(int j=0;j<vec.size();j++)
               {
                    if(vec[j]!=i)vec1.push_back(vec[j]);
               }
               adj[it.first]=vec1;
           }
       }
        
      }
        if(vis[start]==0)
        {
            vis[start]=1;
            for(auto it:adj[start])
            {
                if(dfs(it,adj,vis,numCourses))return true;
            }
        }

       vis[start]=2;
       return false;
   }

    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        
        int n=pre.size();
        vector<int>res;

        unordered_map<int,vector<int>>adj;
         vector<int>vis(numCourses,0);

        for(int i=0;i<n;i++)
        {
            adj[pre[i][0]].push_back(pre[i][1]);
        }

       
        for(int i=0;i<numCourses;i++)
        {
            if(dfs(i,adj,vis,numCourses)==true)return {};
        }
        // for(auto it:order)
        // {   
        //     res.push_back(it);
        //     cout<<it<<" ";
        // }
        return order;
    }
};

int main()
{
    
    return 0;
}