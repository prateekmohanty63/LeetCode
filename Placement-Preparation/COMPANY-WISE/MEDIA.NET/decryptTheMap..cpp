#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int solve(unordered_map<int,vector<int>>&adj,int start)
{
    
}

int main()
{
    int n;
    cin>>n;

    // building an adjcency matrix
    unordered_map<int,vector<int>>adj;

    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }

    return 0;
}