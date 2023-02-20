#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        unordered_map<char,string>mp;
        unordered_map<string,char>mp1;

        if(pattern.size()==1 && pattern==s)return true;

       // s+=" ";
        string a="";
        int k=0;

        s.push_back(' ');

        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=' ')
            a+=s[i];

            if(s[i]==' ')
            {
                if(mp.find(pattern[k])!=mp.end())
                {
                    if(mp[pattern[k]]!=a)
                    {
                        cout<<a<<" "<<pattern[k];
                        return false;
                    }
                    
                }
                  else{
                    mp[pattern[k]]=a;
                   
                }

                if(mp1.find(a)!=mp1.end())
                {
                    if(mp1[a]!=pattern[k])return false;
                }
                else{
                    mp1[a]=pattern[k];
                }
                
              
                  a="";
                   k++;
            }
           
           
        }
       int m=pattern.length();
       

       

       return (k == pattern.size());
    }
};

int main()
{
    
    return 0;
}