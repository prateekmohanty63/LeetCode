#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;





struct DSU{
    vector<int>size;
    vector<int>par;

    DSU(int n)
    {
        size.resize(n,1);
        par.resize(n);
        for(int j=0;j<n;j++)par[j]=j;
    }

    int Leader (int x){
        if(x==par[x])return x;

        return (par[x]=Leader(par[x]));
    }

    void merge(int x,int y)
    {
        x=Leader(x);
        y=Leader(y);

        if(x==y)return ;

        if(size[x]>size[y])swap(x,y);

        size[y]+=size[x];
        par[x]=y;
    }
};

class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        
      int n=vals.size();

      vector<vector<int>>g(n);

      for(auto it:edges)
      {
          g[it[0]].push_back(it[1]);
          g[it[1]].push_back(it[0]);
      }
    
     map<int,vector<int>>val_to_nodes;

     for(int i=0;i<n;i++)
     {
         val_to_nodes[vals[i]].push_back(i);
     }

     DSU dsu(n);

     int result=n;

     vector<bool>is_active(n);

     for(auto [_,indexes]:val_to_nodes){
         for(auto i:indexes){
             for(auto child:g[i]){
                 if(is_active[child])dsu.merge(i,child);
             }

             is_active[i]=true;
         }

         vector<int>leaders;

         for(auto i:indexes)leaders.push_back(dsu.Leader(i));
         sort(leaders.begin(),leaders.end());

         int sz=leaders.size();

         for(int j=0;j<sz;j++){
             long long cnt=0;
             int cur=leaders[j];

             while(j<sz && leaders[j]==cur)j++,cnt++;

             j--;

             result+=(cnt*(cnt-1)/2);
         }
     }

     return result;
}
    
};


class Solution {
public:
    
   int count=0;

    int goodPaths(int rootNode,int parent,unordered_map<int,vector<int>>&adj,unordered_map<int,int>&mp)
    {
         vector<int>vec=adj[rootNode];
         int tempCount=0;
         int count=0;
         

         for(int i=0;i<vec.size();i++)
         {
             if(vec[i]==parent)continue;

            
             int rootVal=mp[rootNode];
             int NodeVal=mp[vec[i]];

          
             if(rootNode<NodeVal){
                 tempCount=0;
                 continue;
             }

             if(rootVal>NodeVal)tempCount++;

             if(rootVal==NodeVal){
               return tempCount;  
             }

         count+=goodPaths(vec[i],rootNode,adj,mp);

         }
         return count;

    }

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        
        unordered_map<int,vector<int>>adj;
        unordered_map<int,int>mp;
        unordered_map<int,bool>visited;

        int n=edges.size();

        for(int i=0;i<n;i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        for(int i=0;i<vals.size();i++)
        {
            mp[i]=vals[i];
        }

       // all single nodes are good paths
        int res=mp.size();
        
       
       return res;
    }
};

int main()
{
    
    return 0;
}