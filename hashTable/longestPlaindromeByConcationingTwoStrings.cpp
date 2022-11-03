#include<iostream>
#include<vector>
#include<vector>
using namespace std;


class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        map<string,int>mp;
        int res=0;
        
        for(int i=0;i<words.size();i++)
        {
            mp[words[i]]++;
        }
        
        bool flag=false;
        
        for(auto x:words)
        {
            string w=x;
            reverse(w.begin(),w.end());
            
            if(w!=x && mp[w]>0 && mp[x]>0)
            {
                res+=4;
                mp[w]--;
                mp[x]--;
                
            }
            else if(w==x && mp[x]>1)
            {
                mp[x]-=2;
                res+=4;
            }
            else if(w==x && mp[x]>0 && !flag)
            {
                mp[x]--;
                res+=2;
                flag=1;
            }
        }
        return res;
    }
};

int main()
{
    
    return 0;
}