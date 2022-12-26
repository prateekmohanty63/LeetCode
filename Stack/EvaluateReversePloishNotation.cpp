#include<iostream>
#include<stack>
#include<vector>

using namespace std;


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        int res=0;

        int n=tokens.size();
        
      
      stack<int>stk;

      for(int i=0;i<n;i++)
      {
          if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="/" && tokens[i]!="*")
          {
              int a=stoi(tokens[i]);

              stk.push(a);
          }
          else{

              long long op1=stk.top();
              stk.pop();
              long long op2=stk.top();
              stk.pop();
              long long  res;

              if(tokens[i]=="/")
              {
                  res=op2/op1;
              }
              else if(tokens[i]=="*")
              {
                  res=op2*op1;
              }
              else if(tokens[i]=="+")
              {
                  res=op2+op1;
              }
              else{
                  res=op2-op1;
              }
              stk.push(res);
          }
      }
     
     return stk.top();

    }
};

int main()
{
    
    return 0;
}