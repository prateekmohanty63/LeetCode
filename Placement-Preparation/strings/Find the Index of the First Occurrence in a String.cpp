#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    
    int isPresent(string a,string b)
    {
        if(a==b)return 0;

        int n=a.length();
        int m=b.length();

        unordered_map<char,int>mp;

        for(int i=0;i<26;i++)
        {
            char ele=char(97+i);
            mp[ele]=i+1;
        }

        int target=0;

        for(int i=0;i<m;i++)
        target+=mp[b[i]];

        int currCount=0;

        for(int i=0;i<m;i++)currCount+=mp[a[i]];

        int k=0;

        for(int i=0;i<=n-m;i++)
        {
            if(currCount==target){
                string e=a.substr(i,m);
                if(e==b)return i;
            }

            // subtract the starting of the string
            currCount-=mp[a[k++]];

            // add the next part
            if(i+m<n)
            currCount+=mp[a[i+m]];
        }
        return -1;
    }

    int strStr(string haystack, string needle) {
        
        int n=haystack.length();
        int m=needle.length();

        if(n<m)return -1;

        return isPresent(haystack,needle);
    }
};

int main()
{
    
    return 0;
}