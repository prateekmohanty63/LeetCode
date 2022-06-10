#include<iostream>
#include<vector>
using namespace std;

// Gives TLE

class Solution {
public:
    
    bool isPresent(string s,string part)
    {
        if(s.find(part)!=string::npos)return true;
        
        return false;
    }
    string removeOccurrences(string s, string part) {
        
        int n=s.size();
        int m=part.size();
        int start=0,end=0;
        vector<int>substring;
        
       
       
        
        while(isPresent(s,part)){
        for(int i=0;i<s.length();i++)
        {
            string res;
            res+=s[i];
            for(int j=i+1;j<s.length();j++)
            {
                res+=s[j];
                
                if(res==part)
                {
                    s.erase(i,part.length());
                }
            }
        }
        }
        return s;
    }
};

int main()
{
    
    return 0;
}