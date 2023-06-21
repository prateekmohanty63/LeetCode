#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        
        string res;
        int n=a.length();
        int m=b.length();

        int sum=0;
        int carry=0;
       
       int k,l;
       l=m-1;
       k=n-1;

       while(k>=0 && l>=0)
       {
           char dig1=a[k];
           char dig2=b[l];

           if(dig1=='1' && dig2=='1'){

               if(carry==0){
               res+='0';
               }
               else {
                   res+='1';
               }
               carry=1;
           }
           else if(dig1=='1' && dig2=='0'){
                if(carry==1){
                    res+='0';
                }
                else{
                    res+='1';
                }
           }
           else if(dig1=='0' && dig2=='1')
           {
               if(carry==1){
                   res+='0';
               }
               else{
                   res+='1';
               }
           }
           else if(dig1=='0' && dig2=='0')
           {
               if(carry==1)res+='1';
               else res+='0';

               carry=0;
           }
           k--;
           l--;
       }

       if(n>m){
           int diff=n-m-1;;

           while(diff>=0)
           {
               char ele=a[diff];

               if(ele=='0'){
                    if(carry==1)res+='1';

                    else res+='0';

                    carry=0;
               }
               else{
                   if(carry==0)res+='1';

                   else res+='0';
               }
               diff--;
           }
       }
       else if(m>n){
             int diff=m-n-1;;

           while(diff>=0)
           {
               char ele=b[diff];

               if(ele=='0'){
                    if(carry==1)res+='1';

                    else res+='0';

                    carry=0;
               }
               else{
                   if(carry==0)res+='1';

                   else res+='0';
               }
               diff--;
           }
       }
      
      if(carry==1)res+='1';

      reverse(res.begin(),res.end());
       // while(k)

       return res;
    }
};

int main()
{
    
    return 0;
}