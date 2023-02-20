#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
using namespace std;

class Solution {
public:

        unordered_map<int,list<int>>adj;
        unordered_map<int,bool>visited;
         vector<vector<int>>res;

         void sourceToTarget(int source,int target,vector<int>vec)
         {
             // base case

             if(source==target)
             {
                 vec.push_back(source);
                 res.push_back(vec);

                 return ;
             }

               vec.push_back(source);

             visited[source]=true;
           
             for(auto it:adj[source])
             {
                 
                 if(visited[it]!=true)
                 {
                     sourceToTarget(it,target,vec);
                    // visited[node]=true;
                 }

                 
             }

             visited[source]=false;
}

      
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
       
        int k=0;
        int n=graph.size();
        
        // building the adjacency matrix

        for(auto nodes:graph)
        {
            for(auto edges:nodes)
            {
                adj[k].push_back(edges);
            }
            k++;
        }

        vector<int>vec;

        sourceToTarget(0,n-1,vec);


        return res;
    }
};

int main()
{
    
    return 0;
}