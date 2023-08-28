#include<iostream>
#include<stack>
#include<string>
#include <bits/stdc++.h>

using namespace std;

int main()
{

    string str1,str2;
    cin>>str1>>str2;
    stack<char>stk1;
    string res;

    int a=str1.size();
    int b=str2.size();

    if(a>b){
        int k=b-1;

       for(int i=0;i<b;i++){
        stk1.push(str2[i]);
       }
       while(!stk1.empty()){
        if(stk1.top()==str1[k]){
            res+=str1[k];
            k--;
        }
        else{
            res="";
            break;
        }
        stk1.pop();
       }
    }
    else{
        int k=a-1;

       for(int i=0;i<a;i++){
        stk1.push(str1[i]);
       }
       while(!stk1.empty()){
        if(stk1.top()==str2[k]){
            res+=str1[k];
            k--;
        }
        else{
            res="";
            break;
        }
        stk1.pop();
       }
    }
    reverse(res.begin(),res.end());
    cout<<res;

    /// Failing 1 test case of ABABAB AND ABAB




/// 2nd approach
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {

        if(str1+str2==str2+str1){
            return str1.substr(0,__gcd(str1.size(),str2.size()));
        }
        else
            return "";
    }
};

}
