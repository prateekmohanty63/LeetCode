#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;

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