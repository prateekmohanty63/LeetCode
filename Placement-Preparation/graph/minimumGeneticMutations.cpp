#include<iostream>
#include<unordered_map>
#include<climits>
#include<vector>
#include<queue>
using namespace std;


// T(N)=O(4^8)

class Solution {
public:
  
  int minimMutations(string startGene,string endGene,unordered_map<string,bool>&mp,vector<char>&strands)
  {
      // queue of pairs
      queue<pair<string,int>>q;

      // pushing the source string into queue with cost 0
      q.push({startGene,0});

      // marking the startGene as visited 
      unordered_map<string,bool>vis;
      vis[startGene]=true;

      // perform the bfs 
      while(!q.empty())               
      {
          pair<string,int>fr=q.front();
          q.pop();
          string currString=fr.first;
          int currCost=fr.second;

          if(currString==endGene)return currCost;

          // substuting the 4 different strands
          for(auto it:strands)
          {
              for(int i=0;i<8;i++)
              {
                  string curr=currString;
                  if(curr[i]!=it)
                  {
                      curr[i]=it;
                      // if the string is present in the back 
                      // and it is not already visited then we push to the queue
                      if(mp.find(curr)!=mp.end() && vis.find(curr)==vis.end())
                      {
                          vis[curr]=true;
                          q.push({curr,currCost+1});
                      }
                  }
              }
          }

      }
      return -1;
  }

    int minMutation(string startGene, string endGene, vector<string>& bank) {
        
        if(startGene==endGene)return 0;

        

        unordered_map<string,bool>mp;

        for(auto it:bank)mp[it]=true;

        if(mp.find(endGene)==mp.end())return -1;
        vector<char>strands={'A','C','G','T'};

        int res=minimMutations(startGene,endGene,mp,strands);

        return res;


    }
};


// Code not working (might be conceptually wrong)
class Solution {
public:
    long long ans=INT_MAX;
    long long  minimMutation(string startGene,string endGene,unordered_map<string,bool>&mp,int i,vector<char>&strands)
    {
        // base case
        int n=startGene.size();
        if(startGene==endGene)return 0;

        if(i>=n)return INT_MAX;
        

        for(auto it:strands)
        {
           string nw=startGene;
           char currChar=nw[i];
           nw[i]=it;

           if(it!=currChar){

           if(mp.find(nw)!=mp.end())
           {
               ans=min(ans,min(minimMutation(startGene,endGene,mp,i+1,strands),1+minimMutation(nw,endGene,mp,i+1,strands)));
           } 
           else ans=min(ans,minimMutation(startGene,endGene,mp,i+1,strands));
         }
           else{
               ans=min(ans,minimMutation(nw,endGene,mp,i+1,strands));
           }
        }
      return ans;
    }
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        
        unordered_map<string,bool>mp;

        for(auto it:bank)mp[it]=true;
        vector<char>vec={'A','C','G','T'};

        int res=minimMutation(startGene,endGene,mp,0,vec);

        return res;
    }
};

int main()
{
    
    return 0;
}