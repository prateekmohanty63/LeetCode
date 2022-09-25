#include<iostream>
using namespace std;

class Solution {
public:
    int divisorSubstrings(int num, int k) {
     
        string a=to_string(num);
        
        int res=0;
    
        int n=a.length();
        
       int start=0;
        
        while(start<=n-k)
        {
            string substr=a.substr(start,k);
            start++;
            int a=stoi(substr);
            
            if(a!=0)
            if(num%a==0)res++;
        }
        return res;
    }
};

int main()
{
    
    return 0;
}