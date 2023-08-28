#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:
     bool solve(vector<int>&stones,int curr,unordered_map<int,bool>&stonePos,int prevJump)
    {
        // base case
        int n=stones.size();
        if(curr==stones[n-1])return true;

        if(curr>stones[n-1])return false;

        if(stonePos.find(curr)==stonePos.end())return false;

        if(prevJump==1)
        return solve(stones,curr+prevJump,stonePos,prevJump) || solve(stones,curr+prevJump+1,stonePos,prevJump+1);

else 
 return solve(stones,curr+prevJump,stonePos,prevJump) || solve(stones,curr+prevJump-1,stonePos,prevJump-1) || solve(stones,curr+prevJump+1,stonePos,prevJump+1);
    }
    bool canCross(vector<int>& stones) {
        
        unordered_map<int,bool>stonePos;
        int n=stones.size();

        for(int i=0;i<n;i++)
        stonePos[stones[i]]=true;

        return solve(stones,1,stonePos,1);
    }
};

int main()
{
    
    return 0;
}