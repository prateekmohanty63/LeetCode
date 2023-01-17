#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
   
   int minCost(string &s,int i,char prev,vector<vector<int>>&dp)
   {
       // base case

       if(i>=s.length())return 0;

       if(dp[i][prev-'0']!=-1)return dp[i][prev-'0'];

       int res1=INT_MAX,res2=INT_MAX;

       if(prev=='0')
       {
           if(s[i]=='0')
           {
               res1=minCost(s,i+1,s[i],dp);
               res2=minCost(s,i+1,'1',dp)+1;
           }
           else{
                res1=minCost(s,i+1,s[i],dp);
                res2=minCost(s,i+1,'0',dp)+1;
           }
       }
       else{

           if(s[i]=='0')
           {
               res1=minCost(s,i+1,'1',dp)+1;
           }
           else{
               res2=minCost(s,i+1,s[i],dp);
           }
       }

       return dp[i][prev-'0']=min(res1,res2);
   }

    int minFlipsMonoIncr(string s) {
        
        vector<vector<int>>dp(s.size(),vector<int>(2,-1));

        return minCost(s,0,'0',dp);

        
    }
};


// 67/93 test cases passed

class Solution {
public:
   
   // we encounter first 1 and convert all 0's after that to 1
   int monoticStringOne(string s,int i)
   {
       // base case
       

       if(i>=s.length())return 0;

       if(s[i]=='0'){
           
           return 1+monoticStringOne(s,i+1);
       }

       return monoticStringOne(s,i+1);
   }

    // we encounter first 0 and make all chars after that as 0
     int monoticStringZero(string s,int i)
   {
       // base case
       

       if(i<0)return 0;

       if(s[i]=='1'){
           
           return 1+monoticStringZero(s,i-1);
       }

       return monoticStringZero(s,i-1);
   }

    int minFlipsMonoIncr(string s) {
        
        int i=0;

        while(i<s.length() && s[i]=='0')i++;

        int res1=monoticStringOne(s,i);

        i=s.length()-1;
       while(i>=0 && s[i]=='1')i--;

        int res2=monoticStringZero(s,i);

        return min(res1,res2);
    }
};

int main()
{
    
    return 0;
}