#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

bool isSame(string a,string b)
{
    if(a.length()!=b.length())return false;

    if(a==b)return false;

    int flag=0;

    for(int i=0;i<a.length();i++)
    {
        if(a[i]!=b[i] && flag==0)
        {
            flag=1;
        }
        else if(a[i]!=b[i] && flag==1)return false;
    }
    return true;
}

void dfs(unordered_map<string,vector<string>>&adj,string node,unordered_map<string,bool>&vis)
{
     vis[node]=true;

     for(auto it:adj[node])
     {
        if(vis.find(it)==vis.end()){
        cout<<it<<" ";
        dfs(adj,it,vis);
        }
     }
}
int main()
{
    int n;
    cin>>n;
    vector<string>vec;

    unordered_map<string,int>stringNum;
    unordered_map<int,string>numString;
    unordered_map<string,vector<string>>adj;

    for(int i=0;i<n;i++)
    {
        string a;
        cin>>a;
        vec.push_back(a);
        stringNum[a]=i;
        numString[i]=a;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(isSame(vec[i],vec[j]))
            {
                 adj[vec[i]].push_back(vec[j]);
                 adj[vec[j]].push_back(vec[i]);
            }
        }
    }

    unordered_map<string,bool>vis;

    for(auto it:adj)
    {
        cout<<it.first<<"->";
        vector<string>vec=it.second;

        for(auto itr:vec)cout<<itr<<" ";

        cout<<endl;
    }

    for(int i=0;i<n;i++)
    {
        if(vis.find(vec[i])==vis.end())
        {
            cout<<vec[i]<<" ";
            dfs(adj,vec[i],vis);
            cout<<endl;
        }
    }
    return 0;
}