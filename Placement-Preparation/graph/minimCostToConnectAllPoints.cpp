#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>

using namespace std;


class Solution {
public:
     typedef pair<int,int> p;
    int dist(int x1,int y1,int x2,int y2)
   {
       int d=abs(x1-x2)+abs(y1-y2);
       return d;
   }
   int solve(unordered_map<int,vector<vector<int>>>&adj)
   {
       priority_queue<p,vector<p>,greater<p>>q;
       int size=adj.size();
       vector<int>vis(size,0);

       q.push({0,0});
       int sum=0;

       while(!q.empty())
       {
            int ind=q.top().second;
            int cost=q.top().first;
            q.pop();

            if(vis[ind]==1)continue;

            vis[ind]=1;

            sum+=cost;

            for(auto it:adj[ind])
            {
                int neigh=it[0];
                int weight=it[1];

                if(vis[neigh]==0)
                {
                    q.push({weight,neigh});
                }
            }
       }

     return sum;
   }
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n=points.size();
        int res=0;

        if(n==1)return 0;

        //priority_queue<int>q;
       unordered_map<int,vector<vector<int>>>mp;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {   
                if(i!=j){
                int dst=dist(points[i][0],points[i][1],points[j][0],points[j][1]);
                 mp[i].push_back({j,dst});
                }
            }

        }
       
       res=solve(mp);
      
        return res;
    }
};

int main()
{
    
    return 0;
}