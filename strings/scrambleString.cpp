#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
   
   unordered_map<string,bool>mp;

    bool isScramble(string s1, string s2) {
        
        // base cases

        int n=s1.size();
        
        // if both string are not equal in size

        if(s2.size()!=n)return false;

        // if both string are equal

        if(s1==s2)return true;

        // if length of strings are 1 and they are not equal return true

        if(n==1)return false;

        string res=s1+"*"+s2;

        if(mp.find(res)!=mp.end())return mp[res];


        for(int i=1;i<n;i++)
        {
            bool withoutswap=(
                // left part of both strings
                isScramble(s1.substr(0,i),s2.substr(0,i)) && 

                // right part of both strings
                isScramble(s1.substr(i),s2.substr(i))
            );

            // if withoutswap return true

            if(withoutswap)return true;

             //ex of withswap: gr|eat  rge|at
			//here we compare "gr" with "at" and "eat" with "rge"

            bool withswap=(
                // left part of first and right part of second

                isScramble(s1.substr(0,i),s2.substr(n-i))

                && 

                isScramble(s1.substr(i),s2.substr(0,n-i))
            );

            if(withswap)return true;
        }

     return mp[res]=false;
    }
};

int main()
{
    
    return 0;
}