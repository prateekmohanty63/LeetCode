#include<iostream>
using namespace std;


class Solution {
public:
   string res;

   bool isPali(string a,int start,int end)
   {
       while(start<=end)
       {
           if(a[start]!=a[end])
           {
              return false;
           }
           start++;
           end--;
       }
       return true;
   }

   void solve(string s,int i)
   {
        int n=s.length();

        if(i>=n)return ;

        int start=i;
        char curr=s[start];

        int k=s.length()-1;

        while(k>=start)
        {
            if(curr==s[k])
            {
                if(isPali(s,start,k))
                {
                    if((k-start+1)>res.length())res=s.substr(start,k-start+1);
                }
            }
            k--;
        }
        return solve(s,i+1);
   }

    string longestPalindrome(string s) {
        
        if(isPali(s,0,s.length()-1))return s;

        solve(s,0);
        return res;
    }
};

int main()
{
    
    return 0;
}