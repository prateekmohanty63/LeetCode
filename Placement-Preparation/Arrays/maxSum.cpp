/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<vector>
#include<cmath>

using namespace std;

long long solve(int numberOfBits,int op,vector<string>&arr,int ind)
{
    // base case
    if(ind>=arr.size())return 0;
    
    if(op<0)return 0;
    
    // finding the complement of the current bit 
    string str;
    for(int i=0;i<arr[ind].size();i++)
    {
        if(arr[ind][i]=='0')str+='1';
        else str+='0';
    }
    
    long long sum=0;
    int l=str.length();
    for(int i=0;i<l;i++){
    if(str[l-1-i]=='1')
     sum+=pow(2,i);
    }
    
    long long sum1=0;
    for(int i=0;i<l;i++)
    {
        if(arr[ind][l-i-1]=='1')
        sum1+=pow(2,i);
    }
    
    return max(sum+solve(numberOfBits,op-1,arr,ind+1),sum1+solve(numberOfBits,op,arr,ind+1));
    
    
}

string toBin(long long n,int numberOfBits)
{
    string res;
    for (int i = numberOfBits; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
           res+='1';
        else
            res+='0';
    }
    string res1;
    
    int k=0;
    while(k<res.length() && res[k]=='0')k++;
    
    for(int i=k;i<res.length();i++)res1+=res[i];
    
    return res1;
}

int main()
{
    vector<string>vec={"11","01"};
    long long res=solve(2,1,vec,0);
    string res1=toBin(res,2);
    
    
    
    cout<<res1;

    return 0;
}
