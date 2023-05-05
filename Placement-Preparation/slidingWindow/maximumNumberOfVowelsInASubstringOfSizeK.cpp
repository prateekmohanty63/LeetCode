#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<cmath>
#include<climits>
using namespace std;


// Time complexity: O(N)
// Space complexity: O(1)
class Solution {
public:
    int maxVowels(string s, int k) {
        
        int ptr1=0;
        int ptr2=k-1;

        int maxVowel=INT_MIN;

        int initialCount=0;

        unordered_map<char,bool>mp;
        mp['a']=true;
        mp['e']=true;
        mp['i']=true;
        mp['o']=true;
        mp['u']=true;

        for(int i=ptr1;i<=ptr2;i++)
        {
            if(mp.find(s[i])!=mp.end())initialCount++;
        }

        maxVowel=max(maxVowel,initialCount);

        while(ptr2+1<s.length())
        {
           if(mp.find(s[ptr1])!=mp.end())initialCount--;

           if(mp.find(s[ptr2+1])!=mp.end())initialCount++;

           maxVowel=max(maxVowel,initialCount);

           ptr2++;
           ptr1++;
        }
        return maxVowel;
    }
};

int main()
{
    
    return 0;
}