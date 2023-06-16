#include<iostream>
using namespace std;

class Solution {
public:
    bool isAbsent(string s)
    {
        int count=0;
        int n=s.length();

        for(int i=0;i<n;i++){
            if(s[i]=='A')count++;
        }

        return count<2;
    }

    bool isLate(string s)
    {
        int n=s.length();

        for(int i=0;i<n-2;i++)
        {
            if(s[i]=='L' && s[i+1]=='L' && s[i+2]=='L')return false;
        }
        return true;
    }
    bool checkRecord(string s) {
        
        return isAbsent(s)&&isLate(s);
    }
};

int main()
{
    
    return 0;
}