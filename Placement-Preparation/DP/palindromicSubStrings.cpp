#include<iostream>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        
        int n=s.length();
        int count=0;

        for(int i=0;i<n;i++)
        {
            int l=i;
            int r=i;

          // odd length palindrome
            while(l>=0 && r<n && s[l]==s[r])
            {
                count++;
                l--;
                r++;
            }

            // even length palindrome
            l=i;
            r=i+1;
            while(l>=0 && r<n && s[l]==s[r])
            {
                count++;
                l--;
                r++;
            }
        }
        return count;
    }
};

int main()
{
    
    return 0;
}