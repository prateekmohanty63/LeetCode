#include<iostream>
#include<climits>
#include<unordered_map>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int maximLen=INT_MIN;
        
        int n=s.length();

        if(s=="")return 0;

        if(n==1)return 1;

        unordered_map<char,int>mp;

        int start=0;
        int end=1;

        mp[s[start]]++;
        

     while(end<s.length())
     {
       mp[s[end]]++;
         if(mp.find(s[end])!=mp.end())
         {
             maximLen=max(maximLen,end-start);
             while(mp[s[end]]!=1)
             {
                mp[s[start]]--;
                start++;
             }
         }
           end++;
     }

     maximLen=max(maximLen,end-start);
        

        return maximLen;
    }
};

int main()
{
    
    return 0;
}