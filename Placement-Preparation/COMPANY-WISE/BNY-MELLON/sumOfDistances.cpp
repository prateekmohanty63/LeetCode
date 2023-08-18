#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin>>n;

    // making the adjacency matrix
    unordered_map<int,vector<int>>adj;

    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        int b;
        cin>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // minimum case 
    int minimDistance=0;
    int maximDistance=0;
    if(n%2==0)
    {
       minimDistance=n;   
    }
    else{
        minimDistance=n+1;
    }

    // maximum case 

    return 0;
}