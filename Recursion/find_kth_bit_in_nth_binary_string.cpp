#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    
    void findString(int &m,int n,string &res)
    {
        if(m==n)
        {
            return ;
        }
        
        if(m==1)res='0';
        
        
        string a=res;
        // inverting the bits;
        
        for(int i=0;i<a.length();i++)
        {
            if(a[i]=='0')a[i]='1';
            else a[i]='0';
        }
        reverse(a.begin(),a.end());
        res+="1";
        res+=a;
        
         m++;
       
        findString(m,n,res);
    }
    char findKthBit(int n, int k) {
        string res;
        if(n==1){
         return '0';
        }
        int m=1;
        findString(m,n,res);
        
        cout<<res;
        
        return res[k-1];
    }
};

int main()
{
    
    return 0;
}