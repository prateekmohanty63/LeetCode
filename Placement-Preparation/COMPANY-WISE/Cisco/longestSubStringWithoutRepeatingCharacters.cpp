#include<iostream>
#include<unordered_map>
#include<climits>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int start=0;
        int end=1;
        int res=INT_MIN;
        int n=s.length();

        if(n==0)return 0;

        unordered_map<char,int>mp;
        mp[s[start]]++;

        while(end<n)
        {
            mp[s[end]]++;

            if(mp[s[end]]==2)
            {
                while(start<end && s[start]!=s[end])
                {
                    mp[s[start]]--;
                    start++;   
                }
              mp[s[start]]--;
              start++;
            }
            res=max(res,end-start+1);
            end++;
        }
       

        if(res==INT_MIN)return 1;
        return res;
    }
};

int main()
{
    
    return 0;
}