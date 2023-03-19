#include<iostream>
#include<stack>
using namespace std;


// with stack 

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

// without stack

class Solution {
public:
    int minAddToMakeValid(string s) {
        
        int openBrackets=0;
        int res=0;

        int n=s.length();

        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                openBrackets++;
            }
            else{
                if(openBrackets>0)
                {
                    openBrackets--;
                }
                else{
                    res++;
                }
            }
        }
        return res+openBrackets;
    }
};

int main()
{
    
    return 0;
}