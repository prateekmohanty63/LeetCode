#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
   
   vector<int>alpha;

   int find(int x)
   {
       if(alpha[x]==-1)return x;

       return alpha[x]=find(alpha[x]);
   }

   void Union(int x,int y)
   {
       int parentx=find(x);
       int parenty=find(y);

       if(parentx==parenty)return ;

       alpha[max(parentx,parenty)]=min(parentx,parenty);
   }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        
       alpha.resize(26,-1);

       for(int i=0;i<s1.size();i++)
       {
           Union(s1[i]-'a',s2[i]-'a');
       }

       for(int i=0;i<baseStr.length();i++)
       {
           baseStr[i]=find(baseStr[i]-'a')+'a';
       }

       return baseStr;
    }
};

int main()
{
    
    return 0;
}