#include<iostream>
#include<unordered_map>

using namespace std;


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if(s1==s2)return true;

        int n=s1.size();
        int m=s2.size();

        if(m<n)return false;

     

        // inserting the chars of s1 in map

        unordered_map<char,int>mp;
        unordered_map<char,int>mp1;

        for(int i=0;i<n;i++)
        {
            mp[s1[i]]++;
        }

        int start=0;
        int end=n-1;

         for(int i=start;i<=end;i++)
            {
                mp1[s2[i]]++;
            }
        
        while(end<m)
        {
         
         if(mp==mp1)return true;
            
           mp1[s2[start]]--;

           if(mp1[s2[start]]==0)mp1.erase(s2[start]);

           start++;

           end++;

           mp1[s2[end]]++;
           

        }

        return false;

    }
};

int main()
{
    
    return 0;
}