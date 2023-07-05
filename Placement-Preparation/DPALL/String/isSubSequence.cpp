#include<iostream>
using namespace std;

class Solution {
public:
    bool solve(string s,string t,int i,int j)
    {
        if(i<0)return true;
        if(j<0)return false;

        if(s[i]==t[j])return solve(s,t,i-1,j-1);

        else return solve(s,t,i,j-1);
    }
    bool isSubsequence(string s, string t) {
        
        int n=s.length();
        int m=t.length();
        return solve(s,t,n-1,m-1);

    }
};

int main()
{
    
    return 0;
}