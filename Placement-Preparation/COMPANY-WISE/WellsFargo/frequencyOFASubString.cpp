#include<iostream>
#include<unordered_map>
#include<cmath>
#include<vector>
using namespace std;

// T(N)=O(n+m)  -- average and best case 
// T(N)=o(n*m)  -- worst case 
// S(N)=O(1)
int rabinKarp(string pattern,string a)
{
    int n=pattern.size();
    int m=a.size();

    if(n>m)return 0;

    unordered_map<char,int>mp;
    int res=0;

    for(int i=0;i<26;i++)
    {
        mp[char(97+i)]=i+1;
    }

    // for(auto it:mp)
    // cout<<it.first<<" "<<it.second<<endl;

    int target=0;
   
    for(int i=0;i<n;i++)target+=(mp[pattern[i]]*pow(10,n-i-1));

    int currCount=0;

    for(int i=0;i<n;i++)
    currCount+=mp[a[i]]*pow(10,n-i-1);

    int start=0;
    int end=n-1;

    while(end<m)
    {
        if(currCount==target)
        {
            string l=a.substr(start,end-start+1);

            if(l==pattern)res++;
        }
         currCount-=mp[a[start]]*pow(10,n-1);

         currCount*=10;

        if(end+1<m)currCount+=mp[a[end+1]];

        start++;
        end++;
    }

    return res;
}


// KMP algorithm

vector<int> prefix_function(string s)
   {
       // T(N)=O(N)
       
       int n=s.size();
       vector<int>pi(n,0);
       int res=0;
       
       for(int i=1;i<n;i++)
       {
           int j=pi[i-1];
           
           while(j>0 && s[i]!=s[j])j=pi[j-1];
           
           if(s[i]==s[j])j++;
           
           pi[i]=j;
       }
       return pi;
   }
    int kmp(string A,string B)
    {
        int n=A.length();
        int m=B.length();
        int pos=-1;
        int res=0;
        
         // constructing the pi table
        vector<int>prefix=prefix_function(B);
        
        
        int i=0,j=0;
        
        while(i<n)
        {
            if(A[i]==B[j])
            {
                i++;
                j++;
            }
            else{
                 if(j!=0)j=prefix[j-1];
                 else i++;
            }
            if(j==m)
            {
               // pos=i-m;
               res++;
            }
        }
        
       return res;
        
    }

int main()
{
    // string pattern;
    // string a;
    // cin>>pattern;
    // cin>>a;

   cout<<rabinKarp("man","dhimanman");
   cout<<endl;
   cout<<kmp("dhimanman","man");
    return 0;
}