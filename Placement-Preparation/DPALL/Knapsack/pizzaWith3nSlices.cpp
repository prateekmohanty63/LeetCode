#include<iostream>
#include<vector>
using namespace std;

// T(N)=O(2*N^2)
// S(N)=O(N)
class Solution {
public:
    int solve(vector<int>&slices,int index,int flag,int slicesEaten,vector<vector<vector<int>>>&dp)
    {
        // base case
        int n=slices.size();

        if(slicesEaten==n/3)return 0;    // each person gets n/3 slices as ther are 3*n slices

        // ensuring that you eat only n slices 
        // makes sure that other 2 people always have a slice to eat after you have picked a particular slice
        
        if(index>=n)return 0;

        if(dp[index][slicesEaten][flag]!=-1)return dp[index][slicesEaten][flag];
        
        int pick,dontPick;

        if(index==0){
            pick=slices[index]+solve(slices,index+2,1,slicesEaten+1,dp);
            dontPick=solve(slices,index+1,0,slicesEaten,dp);
        }
        else{
            if(index==n-1){
                
                if(flag==1)return 0;

                else return slices[index];
            }
            else{
               pick=slices[index]+solve(slices,index+2,flag,slicesEaten+1,dp);
               dontPick=solve(slices,index+1,flag,slicesEaten,dp);
            }
        }

        return dp[index][slicesEaten][flag]=max(pick,dontPick);
        
    }
    int maxSizeSlices(vector<int>& slices) {
        
        int n=slices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n+1,vector<int>(2,-1)));
        int res=solve(slices,0,0,0,dp);

        return res;
    }
};

// T(N)=O(2^N)
// S(N)=O(N)
class Solution {
public:
    int solve(vector<int>&slices,int index,int flag,int slicesEaten)
    {
        // base case
        int n=slices.size();

        if(slicesEaten==n/3)return 0;    // each person gets n/3 slices as ther are 3*n slices
        
        if(index>=n)return 0;
        
        int pick,dontPick;

        if(index==0){
            pick=slices[index]+solve(slices,index+2,1,slicesEaten+1);
            dontPick=solve(slices,index+1,0,slicesEaten);
        }
        else{
            if(index==n-1){
                
                if(flag==1)return 0;

                else return slices[index];
            }
            else{
               pick=slices[index]+solve(slices,index+2,flag,slicesEaten+1);
               dontPick=solve(slices,index+1,flag,slicesEaten);
            }
        }

        return max(pick,dontPick);
        
    }
    int maxSizeSlices(vector<int>& slices) {
        
        int res=solve(slices,0,0,0);

        return res;
    }
};

int main()
{
    
    return 0;
}