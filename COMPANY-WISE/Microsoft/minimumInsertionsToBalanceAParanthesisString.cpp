#include<iostream>
#include<stack>
using namespace std;

// using stack implementation 

class Solution {
public:
    int minInsertions(string s) {
        
        s+='*';
        int n=s.length();
        int count=0;
        stack<char>stk;

        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                stk.push('(');
            }
            else if(s[i]==')')
            {
                if(s[i+1]==')')
                {
                    if(!stk.empty())
                    {
                        stk.pop();
                        i++;
                    }
                    else if(stk.empty())
                    {
                        count++;
                        i++;
                    }
                }
                else
                {
                    if(!stk.empty())
                    {
                        count++;
                        stk.pop();
                    }
                    else if(stk.empty())
                    {
                        count+=2;
                    }
                }
                
            }
        }

        while(!stk.empty())
        {
            count+=2;
            stk.pop();
        }
        return count;
    }
};

int main()
{
    
    return 0;
}