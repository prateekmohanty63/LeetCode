#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int removePalindromeSub(string s) {
        
        string a=s;
        reverse(a.begin(),a.end());
        
        if(a==s)return 1;
        
        return 2;
    }
};

int main()
{
    
    return 0;
}