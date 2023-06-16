#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

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