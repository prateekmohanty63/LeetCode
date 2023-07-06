#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;


// T(N)=O(N^2)
// T(N)=O(N)
class Solution {
public:
    int strToNum(vector<string>&rec,vector<vector<string>>&ind,vector<string>&sup,unordered_map<string,int>&strNum,unordered_map<int,string>&numStr)
    {
        int k=0;
        for(int i=0;i<rec.size();i++)
        {
            if(strNum.find(rec[i])==strNum.end()){
            strNum[rec[i]]=k;
            numStr[k]=rec[i];
            k++;
            }
        }

        for(int i=0;i<ind.size();i++)
        {
            int m=ind[i].size();

            for(int j=0;j<m;j++)
            {
                if(strNum.find(ind[i][j])==strNum.end()){
                strNum[ind[i][j]]=k;
                numStr[k]=ind[i][j];
                k++;
                }
            }
        }
        for(int i=0;i<sup.size();i++)
        {
            if(strNum.find(sup[i])==strNum.end()){
                strNum[sup[i]]=k;
                numStr[k]=sup[i];
                k++;
            }
        }
      return k;
    }
    
    vector<string> topoSort(unordered_map<string,vector<string>>&adj,unordered_map<string,vector<string>>&dep,vector<string>&rec,vector<string>&sup,int k,unordered_map<string,int>&mp,unordered_map<int,string>&mp1)
    {
        // indgree 
        vector<int>indegree(k,0);
        queue<int>q;
        vector<string>res;

        unordered_map<int,string>rc;
        for(auto it:rec)
        {
            int a=mp[it];
            rc[a]=it;
        }

        for(auto it:adj)
        {
            int a=mp[it.first];
            indegree[a]=it.second.size();
        }

        // pushing all elements with in-degree 0

         for(auto it:sup)
         {
            int a=mp[it];
            q.push(a);
         }

         while(!q.empty())     // O(N)
         {
             int fr=q.front();
             q.pop();
             string reci=mp1[fr];

             if(rc.find(fr)!=rc.end())
             {
                 res.push_back(mp1[fr]);
             }
            vector<string>vec=dep[reci];
            for(auto it:vec)       // O(N-1)
            {
                int a=mp[it];
                indegree[a]--;

                if(indegree[a]==0)q.push(a);
            }
         }
    return res;
    }

    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
      //  vector<string>res;

        unordered_map<string,int>mp;
        unordered_map<int,string>mp1;
        unordered_map<string,vector<string>>dep;

       int k=strToNum(recipes,ingredients,supplies,mp,mp1);
        unordered_map<string,vector<string>>adj;

        // building the adjancency matrix
        for(int i=0;i<recipes.size();i++)
        {
            int m=ingredients[i].size();
            for(int j=0;j<m;j++)
            {
               
                adj[recipes[i]].push_back(ingredients[i][j]);
                dep[ingredients[i][j]].push_back(recipes[i]);
            }
        }

        vector<string>res=topoSort(adj,dep,recipes,supplies,k,mp,mp1);

        return res;
    }
};

// T(N)=O(N^3)
// S(N)=O(N)
class Solution {
public:
    int strToNum(vector<string>&rec,vector<vector<string>>&ind,vector<string>&sup,unordered_map<string,int>&strNum,unordered_map<int,string>&numStr)
    {
        int k=0;
        for(int i=0;i<rec.size();i++)
        {
            if(strNum.find(rec[i])==strNum.end()){
            strNum[rec[i]]=k;
            numStr[k]=rec[i];
            k++;
            }
        }

        for(int i=0;i<ind.size();i++)
        {
            int m=ind[i].size();

            for(int j=0;j<m;j++)
            {
                if(strNum.find(ind[i][j])==strNum.end()){
                strNum[ind[i][j]]=k;
                numStr[k]=ind[i][j];
                k++;
                }
            }
        }
        for(int i=0;i<sup.size();i++)
        {
            if(strNum.find(sup[i])==strNum.end()){
                strNum[sup[i]]=k;
                numStr[k]=sup[i];
                k++;
            }
        }
      return k;
    }
    
    vector<string> topoSort(unordered_map<string,vector<string>>&adj,vector<string>&rec,vector<string>&sup,int k,unordered_map<string,int>&mp,unordered_map<int,string>&mp1)
    {
        // indgree 
        vector<int>indegree(k,0);
        queue<int>q;
        vector<string>res;

        unordered_map<int,string>rc;
        for(auto it:rec)
        {
            int a=mp[it];
            rc[a]=it;
        }

        for(auto it:adj)
        {
            int a=mp[it.first];
            indegree[a]=it.second.size();
        }

        // pushing all elements with in-degree 0

         for(auto it:sup)
         {
            int a=mp[it];
            q.push(a);
         }

         while(!q.empty())    // O(N)
         {
             int fr=q.front();
             q.pop();
             string reci=mp1[fr];

             if(rc.find(fr)!=rc.end())
             {
                 res.push_back(mp1[fr]);
             }
             for(auto it:adj)      // O(N)
             {
                 vector<string>vec=it.second;
                 int b=mp[it.first];
                 for(int i=0;i<vec.size();i++)     // O(N-1)
                 {
                     int a=mp[vec[i]];
                     if(fr==a)
                     {
                         indegree[b]--;

                         if(indegree[b]==0)
                         {
                             int b=mp[it.first];
                             q.push(b);
                         }
                     }
                 }
             }
         }
    return res;
    }

    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
      //  vector<string>res;

        unordered_map<string,int>mp;
        unordered_map<int,string>mp1;

       int k=strToNum(recipes,ingredients,supplies,mp,mp1);
        unordered_map<string,vector<string>>adj;

        // building the adjancency matrix
        for(int i=0;i<recipes.size();i++)
        {
            int m=ingredients[i].size();
            for(int j=0;j<m;j++)
            {
               
                adj[recipes[i]].push_back(ingredients[i][j]);
            }
        }

        vector<string>res=topoSort(adj,recipes,supplies,k,mp,mp1);

        return res;
    }
};

int main()
{
    
    return 0;
}