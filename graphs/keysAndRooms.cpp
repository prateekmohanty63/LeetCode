#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


// Beats 97%
class Solution {
public:
    
   

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        queue<int>q;
        q.push(0);
        int n=rooms.size();
        vector<int>visited(n,false);

        while(!q.empty())
        {
            int a=q.front();
            q.pop();
             visited[a]=true;

            for(auto it:rooms[a])
            {
               
                if(!visited[it])
                {
                    q.push(it);
                }

            }
        }
        
        return count( visited.begin(), visited.end(), true ) == rooms.size();
    }
};

// giving runtime error
class Solution {
public:
    
   
   
  // DFS

    bool hasPath(int source,int destination,unordered_map<int,list<int>>&adj)
    {
        if(source==destination)return true;

        int n=adj.size();
        queue<int>q;
       
      vector<bool>visited(n,false);
      q.push(source);

      visited[source]=true;

      while(!q.empty())
      {
          int a=q.front();
          q.pop();

          for(auto it:adj[a])
          {
              if(it==destination)return true;

              if(!visited[it])
              {
                  visited[it]=true;
                  q.push(it);
              }
          }
      }

      
    return false;

    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        // the question is about finding the disconnected node in the graph

        // if there is a disconnected node , we cannot reach it , hence that room cannot be unlocked

        // it all the nodes (rooms) are connected , then we can visit all the rooms


        // building the adjacency matrix
       
       int k=0;
       int n=rooms.size();

      
        unordered_map<int,list<int>>adj;

        for(auto room:rooms)
        {
            for(auto it:room)
            {
               adj[k].push_back(it);
             // adj[it].push_back(k);
            }
            k++;
        }

        
        cout<<endl;
        // checking for a path from 0th node to all other nodes;

        for(int i=0;i<n;i++)
        {
        

            if(!hasPath(0,i,adj))
            {
                cout<<i;
                return false;
            }
        }

        return true;
    }
};

int main()
{
    
    return 0;
}