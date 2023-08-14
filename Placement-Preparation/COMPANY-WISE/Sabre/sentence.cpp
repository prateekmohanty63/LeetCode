#include<iostream>
#include<unordered_map>
using namespace std;

bool isPresent(string a,string b)
{
    int n=a.length();
    int m=b.length();

    if(n<m)return false;
    if(n==m && a==b)return true;
    if(n==m && a!=b)return false;

    int start=0;
    int end=m-1;

    while(end<n)
    {
        string substr=a.substr(start,end-start+1);
        if(substr==b)return true;

        start++;
        end++;
    }
    return false;
}

int main()
{
    string a="geeksforgeeks is the best",b="geeks";
    char c='N';


    int n=a.length();
    int m=b.length();

    if(c=='Y')
    {
         unordered_map<string,bool>mp;
         string str;
         for(int i=0;i<n;i++)
         {
             if(a[i]==' ')
             {
                mp[str]=true;
                str="";
             }
             else{
                str+=a[i];
             }
         }
         mp[str]=true;

         for(auto it:mp)cout<<it.first<<" ";
         cout<<endl;

         if(mp.find(b)!=mp.end())
         cout<<"Present";

         else cout<<"Not present";
         
    }
    else{
      if(isPresent(a,b))cout<<"Present";
      else cout<<"Not present";
    }
    
    return 0;
}