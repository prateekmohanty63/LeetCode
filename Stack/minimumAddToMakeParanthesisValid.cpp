#include<iostream>
#include<stack>
using namespace std;


class Solution {
public:
    int minAddToMakeValid(string s) {
        
        int res=0;

        int n=s.length();

        stack<char>stk;

        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                stk.push('(');
            }
            else{
                if(!stk.empty())
                {
                    stk.pop();
                }
                else{
                    res++;
                }
            }
        }
        while(!stk.empty())
        {
            res++;
            stk.pop();
        }
        return res;
    }
};

int main()
{
    
    return 0;
}