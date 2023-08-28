#include<iostream>
#include<stack>
#include<string>

using namespace std;

 int prec(char c) {
    if(c == '^')
        return 3;
    else if(c == '/' || c=='*')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

int op(char c)
{
    if(c=='-')
    return 1;

    if(c=='+')
    return 2;

    if(c=='*')
    return 3;

    return 4;

}



string infixToPostfix(string s) {
 
    stack<char> st; //For stack operations, we are using C++ built in stack
    string result;
 
    for(int i = 0; i < s.length(); i++) {
        char c = s[i];
 
        // If the scanned character is
        // an operand, add it to output string.
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;
 
        // If the scanned character is an
        // ‘(‘, push it to the stack.
        else if(c == '(')
            st.push('(');
        
        
        // If the scanned character is an ‘)’,
        // pop and to output string from the stack
        // until an ‘(‘ is encountered.
        else if(c == ')') {
            while(st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
 
        //If an operator is scanned
        else {
            while(!st.empty() && prec(s[i]) <= prec(st.top())) {
                result += st.top();
                st.pop(); 
            }
            st.push(c);
        }
    }
         while(!st.empty()) {
        result += st.top();
        st.pop();
    }
 
    return result;
}


int main()
{
    string input;
    cin>>input;

    stack<int>res;

   string postfix= infixToPostfix(input);

   int k=0;

   for(int i=0;postfix[i];++i){
       
     

       if(isdigit(postfix[i])){
            res.push(postfix[i] - '0');
       }

       else{
           int op1=res.top();
           res.pop();
           int op2=res.top();
           res.pop();
           int res1=0;
          

         int x=op(postfix[i]);
        

         if(x==1)
         res1=op2-op1;

         else if(x==2)
         res1=op2+op1;

         else if(x==3)
         res1=op2*op1;

         else{
             res1=op2/op1;
         }
          res.push(res1);
       }


   }
 
   int p=res.top();

}