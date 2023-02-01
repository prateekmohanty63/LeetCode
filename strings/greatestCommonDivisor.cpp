#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
   
   int gcd(int a,int b)
   {
       int result=min(a,b);

       while(result>0)
       {
           if(a%result==0 && b%result==0)break;

           else result--;
       }
       return result;
   }

   

    string gcdOfStrings(string str1, string str2) {
        
        int n=str1.length();
        int m=str2.length();

        if(n==m && str1==str2)return str1;

        else if(n==m && str1!=str2)return "";


         unordered_map<char,bool>mp;

         for(int i=0;i<n;i++)
         {
             mp[str1[i]]=true;
         }

         for(int i=0;i<m;i++)
         {
             if(mp.find(str2[i])==mp.end())return "";
         }
         
         mp.clear();

         for(int i=0;i<m;i++)
         {
             mp[str2[i]]=true;
         }
         for(int i=0;i<n;i++)
         {
             if(mp.find(str1[i])==mp.end())return "";
         }

         int ptr1=0;

         while(ptr1<n && ptr1<m)
         {
             if(str1[ptr1]!=str2[ptr1])return "";

             ptr1++;
         }
        

         int a=gcd(n,m);

         cout<<a;

      
         
         if(n>m)
         {
             int r=n/a;
             string res;
             for(int i=0;i<r;i++)
             {
                res+=str2.substr(0,a);
             }

             if(res!=str1)return "";

             return str1.substr(0,a);
         }
         else{

             int r=m/a;
             string res;
             for(int i=0;i<r;i++)
             {
                res+=str1.substr(0,a);
             }

             if(res!=str2)return "";

             return str1.substr(0,a);
         }
     

         
    }
};

int main()
{
    
    return 0;
}