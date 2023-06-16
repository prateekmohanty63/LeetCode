#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:
    int mod=1e9+7;
   long long solve(int n,int late,int absent,vector<vector<vector<long long>>>&dp)
   {
       // base case
       if(n==0)return 1;

       if(dp[n][late][absent]!=-1)return dp[n][late][absent];

       long long ans=0;

       if(absent==1)
       {
           // he can be absent atmost 1 day
           // if last char is absent , then late gets reset
           ans+=solve(n-1,2,absent-1,dp)%mod;
       }

       if(late>0){
           ans+=solve(n-1,late-1,absent,dp)%mod;
       }

       // if present , late gets reset
       // absent remains same
       ans+=solve(n-1,2,absent,dp)%mod;

       return dp[n][late][absent]=ans%mod;


   }
    int checkRecord(int n) {
        
        vector<vector<vector<long long>>>dp(n+1,vector<vector<long long>>(3,vector<long long>(2,-1)));
        return solve(n,2,1,dp);
    }
};


// T(N)=O(n^2)
class Solution {
public:
    vector<string>vec;
    int combinations(int n,int absentPos,string str,unordered_map<string,int>&dp)
    {
        // base case
        if(absentPos==0)return 0;

        if(n==0){
            //vec.push_back(str);
          return 1;
        }

        string a=to_string(n)+"*"+to_string(absentPos)+"*"+str;

        if(dp.find(a)!=dp.end())return dp[a];

       

        // we have 3 options either to put A , L or P
        int putL=0;

        int putA=combinations(n-1,absentPos-1,str+'A',dp);
        
        if(str.length()>=2 && str[str.length()-1]=='L' && str[str.length()-2]=='L')
        putL=0;
        else putL=combinations(n-1,absentPos,str+'L',dp);

        int putP=combinations(n-1,absentPos,str+'P',dp);

        return dp[a]=putA+putL+putP;
    }
    int checkRecord(int n) {
        
        string str;
        //vector<vector<int>>dp(n+1,vector<int>(3,-1));

        unordered_map<string,int>dp;

        int res=combinations(n,2,str,dp);
        
      //  for(auto it:vec)cout<<it<<" ";

        return res;
    }
};

int main()
{
    
    return 0;
}