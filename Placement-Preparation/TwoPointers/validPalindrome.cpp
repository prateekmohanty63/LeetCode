#include<iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        
        string a;

        int n=s.size();

        for(int i=0;i<n;i++)
        {
            if(iswalnum(s[i])==0)continue;

            if(s[i]>='A' && s[i]<='Z')
            {
                a+=tolower(s[i]);
            }
            else a+=s[i];
        }
        cout<<a;
        int ptr1=0;
        int ptr2=a.size()-1;

        while(ptr1<=ptr2)
        {
            if(a[ptr1]!=a[ptr2])return false;

            ptr1++;
            ptr2--;
        }

        return true;
    }
};

int main()
{
    
    return 0;
}