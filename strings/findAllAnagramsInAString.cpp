#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        // sorting p 

        sort(p.begin(),p.end());
        vector<int>res;

        int ptr1=0;
        

        int m=p.length();

        while(ptr1+m<=s.length())
        {
            string a=s.substr(ptr1,m);

            sort(a.begin(),a.end());

            if(a==p)res.push_back(ptr1);

            ptr1++;

        }

        return res;
    }
};

int main()
{
    
    return 0;
}