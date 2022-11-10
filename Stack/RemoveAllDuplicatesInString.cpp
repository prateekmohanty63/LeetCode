#include<iostream>
#include<unordered_map>
using namespace std;


class Solution {
public:

     bool noDuplicate(string a)
     {
         int n=a.length();

         for(int i=0;i<n-1;i++)
         {
             if(a[i]==a[i+1])return false;
         }
         return true;
     }

     string removeDup(string a,unordered_map<string,string>&dp)
     {
         // base case


         if(noDuplicate(a))return a;

         if(dp.find(a)!=dp.end())return dp[a];

         int n=a.length();

         for(int i=0;i<n-1;i++)
         {
             if(a[i]==a[i+1])
             {
           

                 return removeDup(a.substr(0,i)+a.substr(i+2,n-(i+2)));
             }
         }
         return a;
     }
    string removeDuplicates(string s) {
        
        if(noDuplicate(s))return s;
        
        unordered_map<string,string>dp;

       

        return removeDup(s,dp);
    }
};

int main()
{
    
    return 0;
}