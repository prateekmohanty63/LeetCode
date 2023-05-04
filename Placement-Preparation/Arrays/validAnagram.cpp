#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    bool isAnagram(string s, string t) {
        
        unordered_map<char,int>mp;

        // T(n)=O(N)
        // S(n)=O(N)
       
       if(s.size()!=t.size())return false;

       for(int i=0;i<s.size();i++)
       {
           mp[s[i]]++;
           mp[t[i]]--;
       }

       for(auto it:mp)
       {
           if(it.second!=0)return false;
       }

       return true;

    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        // T(N)=O(nlogn)
        // S(N)=O(1)
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        if(s==t)return true;

        return false;
    }
};

int main()
{
    
    return 0;
}