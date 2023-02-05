#include<iostream>
using namespace std;

// 37/157 cases passed (TLE)
class Solution {
public:
   
   int minOp(string s,int i,char change)
   {
       // base case
       if(i>=s.length())return 0;

       if(s[i]=='a' && change=='a')
       {
           return minOp(s,i+1,'a');
       }

       else if(s[i]=='a' && change=='b')
       {
           return 1+minOp(s,i+1,'b');
       }

       else if(s[i]=='b' && change=='a')
       {
           return min(1+minOp(s,i+1,'a'),minOp(s,i+1,'b'));
       }
       else 
       {
           return minOp(s,i+1,'b');
       }
   }

    int minimumDeletions(string s) {
        
        int ptr=0;

        while(ptr<s.length() && s[ptr]=='a')ptr++;

       // string is already balanced

        if(ptr==s.length())return 0;

        int res=minOp(s,0,'a');

        return res;
    }
};

int main()
{
    
    return 0;
}