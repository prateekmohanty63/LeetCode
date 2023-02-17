#include<iostream>
#include<unordered_map>
#include<climits>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n=s.length();

        unordered_map<char,int>mp;

        int start=0,end=0;

        int maxLength=INT_MIN;


        while(end<n)
        {
            if(mp.find(s[end])==mp.end())
            {
                mp[s[end]]++;
                end++;
            }
            else{
                if(mp[s[end]]==0)
                {
                    mp[s[end]]++;
                    end++;
                }
                else{
                    maxLength=max(maxLength,end-start);
                    char rmv=s[end];

                    while(mp[rmv]!=0)
                    {
                        mp[s[start]]--;

                        start++;
                    }

                }
            }
        }
         maxLength=max(maxLength,end-start);
         return maxLength;

    }
};

int main()
{
    
    return 0;
}