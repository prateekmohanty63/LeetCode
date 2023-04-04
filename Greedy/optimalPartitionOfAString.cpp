#include<iostream>
#include<unordered_map>
using namespace std;


class Solution {
public:
    int partitionString(string s) {
        
        int minimPartation=1;

        int n=s.length();

        unordered_map<char,bool>mp;

        for(int i=0;i<n;i++)
        {
            if(mp.find(s[i])!=mp.end())
            {
                minimPartation++;
                mp.clear();
                mp[s[i]]=true;
            }
            else{
                mp[s[i]]=true;
                continue;
            }
        }
        return minimPartation;
    }
};

int main()
{
    
    return 0;
}