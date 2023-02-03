#include<iostream>
using namespace std;


class Solution {
public:
   
   bool isOne(string a)
   {
       int n=a.length();

       if(a[n-1]=='1')
       {
           int flag=0;
           for(int i=0;i<n-1;i++)
           {
               if(a[i]=='1')flag=1;
           }

           if(flag==0)return true;

           else return false;
       }

       return false;
   }

    int numSteps(string s) {
        
        int numberOfSteps=0;
        int n=s.length();

         while(!isOne(s))
         {
             // if the number is odd
             n=s.length();

             if(s[n-1]=='1')
             {
                 int ptr=n-1;
                 int flag=0;

                 while(ptr>=0)
                 {
                     if(s[ptr]=='0')
                     {
                         s[ptr]='1';
                         flag=1;

                         for(int i=ptr+1;i<n;i++)s[i]='0';
                         break;

                     }
                     ptr--;
                 }

                 if(flag==0)
                 {
                     string a="1";

                     for(int i=0;i<n;i++)a+='0';

                     s=a;
                 }
             }
             else{
                // number is even

                string a;
                a="0";
                n=s.length();

                for(int i=0;i<n-1;i++)
                {
                    a+=s[i];
                }
                s=a;
             }
             numberOfSteps++;

         }

         return numberOfSteps;
    }
};

int main()
{
    
    return 0;
}