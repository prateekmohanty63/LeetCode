#include<iostream>
#include<vector>

using namespace std;



class Solution {
public:
    int solve(vector<int>&nums,int start,int end,int flag)
    {
        //  base case
        if(start>end)return 0;
        
        if(flag==0)
        {
            // it is the turn of player-1
            return max(nums[start]+solve(nums,start+1,end,1),nums[end]+solve(nums,start,end-1,1));
        }
        else{
           // it is the turn of player-2
           // he will try to minimize the score of player 1
           return min(solve(nums,start+1,end,0),solve(nums,start,end-1,0));
        }
    }
    bool PredictTheWinner(vector<int>& nums) {
        
        int sum=0;
        for(auto it:nums)sum+=it;
        int n=nums.size();

        int player1=solve(nums,0,n-1,0);
        int player2=sum-player1;

        return player1>=player2;
        
    }
};

int main()
{
    
    return 0;
}