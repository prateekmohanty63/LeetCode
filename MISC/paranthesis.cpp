#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

bool para(string s)
{
    int count=0;

    int b=s.length();

    stack<char> stack1;

    for(int i=0;i<b;i++)
    {
        if(stack1.empty())
        {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
                stack1.push(s[i]);

               else
                return false;
        }

        else if(s[i]=='(' || s[i]=='[' || s[i]=='{')
                    stack1.push(s[i]);

        else{
            if(stack1.top()=='(' && s[i]==')')
                stack1.pop();

            else if(stack1.top()=='{' && s[i]=='}')
                stack1.pop();

            else if(stack1.top()=='[' && s[i]==']')
                stack1.pop();

            else return false;
        }
    }

    if(stack1.empty())
        return true;
    else
        return false;
}


int main()
{
    string b;
    cin>>b;
    if(para(b))
        cout<<"YES";
    else
        cout<<"NO";

}

