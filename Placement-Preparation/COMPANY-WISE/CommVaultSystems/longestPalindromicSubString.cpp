#include<iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        
        int n=s.length();
        string res;
        int len=-1;

        for(int i=0;i<n;i++)
        {
            // checking for odd length palindrome
            int ptr1=i-1;
            int ptr2=i+1;

            while(ptr1>=0 && ptr2<n && s[ptr1]==s[ptr2])
            {
                ptr1--;
                ptr2++;
            }
            if((ptr2-ptr1-1)>len)
            {
                len=(ptr2-ptr1-1);
                res=s.substr(ptr1+1,len);
                cout<<len<<" "<<res<<endl;
            }

            // checking for even length palindrome
            ptr1=i;
            ptr2=i-1;

            while(ptr1>=0 && ptr2>=0 && ptr2<n && s[ptr1]==s[ptr2])
            {
                ptr1--;
                ptr2++;
            }

            if((ptr2-ptr1-1)>len)
            {
                len=(ptr2-ptr1-1);
                res=s.substr(ptr1+1,len);
               // cout<<len<<" "<<res<<endl;
            }
        }
        return res;
    }
};

int main()
{
    
    return 0;
}