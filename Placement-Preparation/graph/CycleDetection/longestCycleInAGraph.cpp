#include<iostream>
#include<vector>
#include<climits>

using namespace std;


class Solution {
public:
    int answer=INT_MIN;

    void solve(vector<int>&edges,int source,vector<int>&visited,vector<int>&recVis,vector<int>&count)
    {
         // mark visited as true and rec vis as true
         visited[source]=true;
         recVis[source]=true;
         
          int nextNode=edges[source];
         if(nextNode!=-1){

         if(visited[nextNode]==0)
         {
             count[nextNode]=count[source]+1;
             solve(edges,nextNode,visited,recVis,count);
         }
         else{
             if(recVis[nextNode]==1)
             {
                 answer=max(answer,count[source]-count[nextNode]+1);
             }
         }
         }
         recVis[source]=0;
    }
    int longestCycle(vector<int>& edges) {
        
        int n=edges.size();
        vector<int>vis(n,0);
        vector<int>recVis(n,0);
        vector<int>count(n,1);

        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                solve(edges,i,vis,recVis,count);
            }
        }

        if(answer==INT_MIN)return -1;
        return answer;
    }
};

int main()
{
    
    return 0;
}