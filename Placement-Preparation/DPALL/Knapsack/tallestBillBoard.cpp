#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

// This solution will also give TLE

// and it we take a 3d DP of dp[n][5001][5001]  (max sum can be 5000 , given in constraints)
// this will give memory limit exceeded

class Solution {
public:
    int solve(vector<int>&rods,int index,int rod1,int rod2 ,unordered_map<string,int>&dp)
    {
        // base case
        int n=rods.size();
        int ans=INT_MIN;

        if(rod1==rod2){
           // cout<<rod1<<" "<<rod2<<endl;
            ans=max(ans,rod1);
        }

        if(index>=n)return ans;

       string state=to_string(index)+"*"+to_string(rod1)+"*"+to_string(rod2);

       if(dp.find(state)!=dp.end())return dp[state];

        
       ans=max(ans,solve(rods,index+1,rod1+rods[index],rod2,dp));
       ans=max(ans,solve(rods,index+1,rod1,rod2+rods[index],dp));
       ans=max(ans,solve(rods,index+1,rod1,rod2,dp));

       return dp[state]=ans; 


    }
    int tallestBillboard(vector<int>& rods) {
        
        int n=rods.size();

        // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(5001,vector<int>(5001,-1)));

        unordered_map<string,int>dp;

       
        int res=solve(rods,0,0,0,dp);

        return res;


    }
};


// T(N)=O(3^n)
// S(N)=O(N)

class Solution {
public:
    int solve(vector<int>&rods,int index,int rod1,int rod2 )
    {
        // base case
        int n=rods.size();
        int ans=INT_MIN;

        if(rod1==rod2){
            cout<<rod1<<" "<<rod2<<endl;
            ans=max(ans,rod1);
        }

        if(index>=n)return ans;

        
       ans=max(ans,solve(rods,index+1,rod1+rods[index],rod2));
       ans=max(ans,solve(rods,index+1,rod1,rod2+rods[index]));
       ans=max(ans,solve(rods,index+1,rod1,rod2));

       return ans; 


    }
    int tallestBillboard(vector<int>& rods) {
        
        int n=rods.size();

       
        int res=solve(rods,0,0,0);

        return res;


    }
};

int main()
{
    
    return 0;
}