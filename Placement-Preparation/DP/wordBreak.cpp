#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
   
   bool solve(string s,unordered_map<string,bool>&wordDict,unordered_map<string,bool>&mp)
   {
       // base case
       if(wordDict.find(s)!=wordDict.end())return true;

       if(mp.find(s)!=mp.end())return mp[s];

       for(int i=0;i<s.length();i++)
       {
           string left=s.substr(0,i+1);
           string right=s.substr(i+1);

           if(wordDict.find(left)!=wordDict.end())
           {
               bool ros=solve(right,wordDict,mp);

               if(ros==true)return mp[s]=true;
           }
       }
       return mp[s]=false;
   }

    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n=s.length();
        int m=wordDict.size();
        unordered_map<string,bool>mp;
        unordered_map<string,bool>dp;

        for(auto it:wordDict)mp[it]=true;

        return solve(s,mp,dp);
    }
};

int main()
{
    
    return 0;
}