#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
   
   int maxMoney(vector<int>&nums,int i,bool firstPicked,unordered_map<string,int>&dp)
   {
       int n=nums.size();
       // base case
       
       if(i>=n)return 0;

       if(i==n-1 && firstPicked==true)return 0;

       string res=to_string(i)+"*"+to_string(firstPicked);
       if(dp.find(res)!=dp.end())return dp[res];

       int pick,notPick;

       if(i==0)
       {
           pick=nums[i]+maxMoney(nums,i+2,true,dp);
           notPick=maxMoney(nums,i+1,firstPicked,dp);
       }
       else{
           pick=nums[i]+maxMoney(nums,i+2,firstPicked,dp);
           notPick=maxMoney(nums,i+1,firstPicked,dp);
       }

       return dp[res]=max(pick,notPick);

   }

    int rob(vector<int>& nums) {
        int n=nums.size();
       
     unordered_map<string,int>dp;
        return maxMoney(nums,0,false,dp);
    }
};

int main()
{
    
    return 0;
}