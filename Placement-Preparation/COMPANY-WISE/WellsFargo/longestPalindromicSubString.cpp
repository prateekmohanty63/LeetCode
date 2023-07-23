#include<iostream>
#include<climits>
using namespace std;


class Solution{   
public:
    string longestPalindrome(string S){
        // code here 
        
        string res;
        int maxLength=INT_MIN;
        int n=S.length();
        
        for(int i=0;i<n;i++)
        {
            // generating even length palindrome
            int ptr1=i;
            int ptr2=i+1;
            
            while(ptr1>=0 && ptr2<n && S[ptr1]==S[ptr2])
            {
                
                    ptr1--;
                    ptr2++;
            }
            if((ptr2-ptr1-1)>maxLength)
            {
                maxLength=(ptr2-ptr1-1);
                res=S.substr(ptr1+1,maxLength);
            }
            
            // generating odd length palindrome
            ptr1=i-1;
            ptr2=i+1;
            
            while(ptr1>=0 && ptr2<n && S[ptr1]==S[ptr2])
            {
                ptr1--;
                ptr2++;
            }
            
            if((ptr2-ptr1-1)>maxLength)
            {
                maxLength=(ptr2-ptr1-1);
                res=S.substr(ptr1+1,maxLength);
            }
        }
        if(maxLength==INT_MIN)
        {
            string a;
            a+=S[0];
            return a;
        }
        return res;
        
    }
};

int main()
{
    
    return 0;
}