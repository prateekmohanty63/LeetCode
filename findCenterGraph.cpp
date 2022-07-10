#include<iostream>
#include<algorithm>
#include<list>
#include<map>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        
        // making the adjacent graph
        map<int,list<int>>adj;
        
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        int target=adj.size();
        
        for(auto i:adj)
        {
            if(i.second.size()==target-1)return i.first;
        }
        return -1;
    }
};


int main()
{

}