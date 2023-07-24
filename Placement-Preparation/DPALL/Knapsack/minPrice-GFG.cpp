//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        if(a[0]==b[0])return a[1]>b[1];
        
        return a[0]<b[0];
    }
    long long solve(int n,vector<vector<int>>&vec,int ind,int freePoints,vector<vector<long long>>&dp)
    {
        // base case
        if(ind>=n)
        {
            if(freePoints>=0)return 0;
            
            return INT_MAX;
        }
        
        if(n-ind<=freePoints)return 0;
        
        if(dp[ind][freePoints+500]!=-1)return dp[ind][freePoints+500];
        
        
          // we have the option of buying this item or not using points to buy it
        return dp[ind][freePoints+500]=min(vec[ind][0]+solve(n,vec,ind+1,freePoints+vec[ind][1],dp),solve(n,vec,ind+1,freePoints-1,dp));
        
          
        
    }
    long long minCost(int n, vector<int> &p, vector<int> &f) {
        // code here
        
        vector<vector<int>>vec;
        for(int i=0;i<n;i++)
        {
            vector<int>v;
            v.push_back(p[i]);
            v.push_back(f[i]);
            vec.push_back(v);
        }
        vector<vector<long long>>dp(n,vector<long long>(n+500,-1));
        
        long long res=solve(n,vec,0,0,dp);
        
        return res;
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        cin>>n;
        
        vector<int> p(n) , f(n);
        
        for(auto &i:p){
            cin>>i;
        }
        
        for(auto &i:f){
            cin>>i;
        }
        
        Solution obj;
        long long res = obj.minCost(n, p, f);
        
        cout<<res<<endl;
        
    }
}


// } Driver Code Ends

int main()
{
    
    return 0;
}