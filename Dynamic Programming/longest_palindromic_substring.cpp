#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;

// NOTE THE IDEA IS DONT USE A FUNCTION TO CHECK PALINDROME
// IF IT IS PALINDROME JUST USE TWO POINTER METHOD TO SEE IF THE CHARACTERS YOU ARE ADDING IS SAME OR NOT

class Solution {
public:
    
    // idea is dont make a function which chekcs if a string is palindrome
    string longestPalindrome(string s) {
        
       
        int max=INT_MIN;
        string res;
        int n=s.length();
        
        // odd length palindrome
        for(int i=0;i<n;i++)
        {
            int l=i,r=i;
            
            while(l>=0 && r<n && s[l]==s[r])
            {
                int len=r-l+1;
                if(len>max)
                {
                    max=len;
                    res=s.substr(l,r-l+1);
                }
                l--;
                r++;
                
            }
            
            // even length
             l=i;
             r=i+1;
            
            while(l>=0 && r<n && s[l]==s[r])
            {
                int len=r-l+1;
                if(len>max)
                {
                    max=len;
                    res=s.substr(l,r-l+1);
                }
                l--;
                r++;
            }
        }
        
        //  even length palindrome
      
         return res; 
}
};

// though this solution is correct , it gives TLE

class Solution {
public:
    
    bool isPali(string s)
    {
        string a=s;
        reverse(s.begin(),s.end());
        
        if(a==s)return true;
        
        return false;
    }
    string longestPalindrome(string s) {
        
        if(isPali(s))return s;
        
        int n=s.size();
        int max=INT_MIN;
        string res;
        
        
        // generating all the substring from the given word
        
        for(int i=0;i<=n;i++)
        {
            for(int j=1;i<=n-i;j++)
            {
                string a=s.substr(i,j);
              
                if(isPali(a) && a.length()>max)
                {
                      cout<<a<<" ";
                    max=a.length();
                    res=a;
                }
                
            }
        }
    return res;  
}
};

int main()
{
    
    return 0;
}