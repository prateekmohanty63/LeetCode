#include<iostream>
using namespace std;

// faster than 100%
class Solution {
public:
    string removeDigit(string number, char digit) {
        
        string res="";

        int n=number.length();
        
        for(int i=0;i<n;i++)
        {
            string a=number;
            
            if(number[i]==digit)
            {
                a.erase(i,1);
                if(a>res)res=a;
            }
        }

        return res;
    }
};

int main()
{
    
    return 0;
}