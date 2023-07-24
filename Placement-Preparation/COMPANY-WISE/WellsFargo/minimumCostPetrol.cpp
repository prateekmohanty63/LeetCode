#include<iostream>
#include<vector>
#include<climits>
using namespace std;

long long solve(vector<int>&vol,vector<int>&cost,int capacity,int ind)
{
    int n=vol.size();
    // base case 
    if(capacity==0)return 0;

    if(ind>=n)return INT_MAX;

    if(vol[ind]<=capacity)
    {
        return min(cost[ind]+solve(vol,cost,capacity-vol[ind],ind+1),solve(vol,cost,capacity,ind+1));
    }
    else{
        return solve(vol,cost,capacity,ind+1);
    }
}

int main()
{
    int n,cap;
    cin>>n;
    cin>>cap;
    vector<int>vol;
    vector<int>cost;

    for(int i=0;i<n;i++)
    {
        int v,c;
        cin>>v>>c;
        vol.push_back(v);
        cost.push_back(c);
    }

    int res=solve(vol,cost,cap,0);
    cout<<res;
    return 0;
}