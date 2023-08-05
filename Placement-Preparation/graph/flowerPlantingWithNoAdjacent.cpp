#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:
    vector<int>res;

    void solve(int &n,unordered_map<int,vector<int>>&adj,int ind,vector<int>&vec)
    {
        // base case
        if(ind==n+1){
            for(int i=1;i<=n;i++)
            {
                if(vec[i]==-1)return ;
            }
        
            res=vec;
            return ;
        }
       

          bool type1=true;
          bool type2=true;
          bool type3=true;
          bool type4=true;
        // checking the neightbours of the current node
        for(auto &neigh:adj[ind])
        {
            int flower=vec[neigh];

            if(flower==1)type1=false;
            if(flower==2)type2=false;
            if(flower==3)type3=false;
            if(flower==4)type4=false;

        }


            if(type1==true)
            {
                vec[ind]=1;
                solve(n,adj,ind+1,vec);
                vec[ind]=-1;
               
            }
           else if(type2==true)
            {
                vec[ind]=2;
                solve(n,adj,ind+1,vec);
                vec[ind]=-1;
               
            }
           else if(type3==true)
            {
                vec[ind]=3;
                solve(n,adj,ind+1,vec);
                vec[ind]=-1;
               
            }
           else if(type4==true)
            {
                vec[ind]=4;
                solve(n,adj,ind+1,vec);
                vec[ind]=-1;
               
            }
         
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        
        unordered_map<int,vector<int>>adj;
        int m=paths.size();

        for(int i=0;i<m;i++)
        {
            adj[paths[i][0]].push_back(paths[i][1]);
            adj[paths[i][1]].push_back(paths[i][0]);
        }
       
       
       vector<int>vec(n+1,-1);
       solve(n,adj,1,vec);
       vector<int>res1;
       for(int i=1;i<=n;i++)res1.push_back(res[i]);

       return res1;

    }
};

int main()
{
    
    return 0;
}