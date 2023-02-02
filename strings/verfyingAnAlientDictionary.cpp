#include<iostream>
#include<unordered_map>
#include<climits>
#include<vector>
using namespace std;



class Solution {
public:
   
   bool isTrue(string a,string b,unordered_map<char,int>&mp,int i)
   {
       int n=a.length();
       int m=b.length();

       
     if(i>=n)return true;

       int pos1=mp[a[i]];
       int pos2=mp[b[i]];

       if(pos1<pos2)return true;

       if(pos1>pos2)return false;

       else return isTrue(a,b,mp,i+1);


       
   }

    bool isAlienSorted(vector<string>& words, string order) {
        
        // storing the letters with position in unordered map to find the sequence easily

        unordered_map<char,int>mp;

        int n=order.length();
        int m=words.size();

        for(int i=0;i<n;i++)
        {
            mp[order[i]]=i;
        }
        mp['.']=-1;


        int maxLength=INT_MIN;

        for(int i=0;i<words.size();i++)
        {
            int a=words[i].length();
            maxLength=max(maxLength,a);
        }

         for(int i=0;i<words.size();i++)
         {
             int currLength=words[i].length();

             for(int j=0;j<maxLength-currLength;j++)
             {
                 words[i]+='.';
             }
         }

         for(int i=0;i<m-1;i++)
         {
             string a=words[i];
             string b=words[i+1];

             if(!isTrue(a,b,mp,0))return false;
         } 

       return true;
    }
};

int main()
{
    
    return 0;
}