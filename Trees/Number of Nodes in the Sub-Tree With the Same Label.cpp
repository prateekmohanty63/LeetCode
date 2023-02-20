#include<iostream>
#include<unordered_map>
#include <vector>
using namespace std;


class Solution {
public:
   


   void sameLabel(
   unordered_map<int,vector<int>>&adj,int rootNode,int parent,string &labels,vector<int>&freqMap,vector<int>&solution)
   {

       int prevCount=freqMap[labels[rootNode]-'a'];

       freqMap[labels[rootNode]-'a']+=1;
      

      for(auto it=adj[rootNode].begin();it!=adj[rootNode].end();it++)
      {
          
             if(*it==parent)continue;

             sameLabel(adj,*it,rootNode,labels,freqMap,solution);

            
      }

        solution[rootNode]=freqMap[labels[rootNode]-'a']-prevCount;

   }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        
       
        // adj list

   unordered_map<int,vector<int>>adj;
        

        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
          adj[edges[i][1]].push_back(edges[i][0]);
        }

       vector<int>solution(n,0);
       vector<int>freqMap=vector<int>(26,0);
         
         sameLabel(adj,0,0,labels,freqMap,solution);


        return solution;
    }
};

int main()
{
    
    return 0;
}