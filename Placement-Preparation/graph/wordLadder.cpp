#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;


// T(N)= n*(26*m)

class Solution {
public:
    
    int bfs(string beginWord,string endWord,unordered_map<string,bool>&mp,vector<char>&vec)
    {
         // queue for implementing the bfs
         queue<pair<string,int>>q;

         int n=beginWord.length();
        
         // push source with cost 0
         q.push({beginWord,0});

         // mark the source as visited
         unordered_map<string,bool>vis;
         vis[beginWord]=true;

         // performing the bfs
         while(!q.empty())        // <- O(N)
         {
             pair<string,int>fr=q.front();
             q.pop();
             string currString=fr.first;
             int currCost=fr.second;

            // cout<<currString<<" ";

             if(currString==endWord)return currCost;

             // changing the strands in the word
             for(auto it:vec)             // <- O(26)
             {
                 for(int i=0;i<n;i++)     // <- O(n)
                 {
                     string a=currString;
                     if(a[i]!=it)
                     {
                         a[i]=it;

                         if(mp.find(a)!=mp.end() && vis.find(a)==vis.end())
                         {
                             vis[a]=true;
                             q.push({a,currCost+1});        // <- O(1)
                         } 
                     }
                 }
             }
         }
         return 0;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_map<string,bool>mp;

        for(auto it:wordList)mp[it]=true;
        
        if(mp.find(endWord)==mp.end())return 0;
        vector<char>vec={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

        int res=bfs(beginWord,endWord,mp,vec);

        if(res==0)return 0;

        return res+1;

    }
};

int main()
{
    
    return 0;
}