#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

// T(N)=O(n)

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        
      int n=s.length();
      int m=goal.length();

      if(n!=m)return false;

      unordered_map<char,vector<int>>mp;

      for(int i=0;i<n;i++)mp[s[i]].push_back(i);  // O(n)

      int flag=0;

       for(int i=0;i<n;i++)     // O(n)
       {
           if(s[i]!=goal[i])
           {
              char ch=s[i];
              char tar=goal[i];
            

              if(mp.find(tar)==mp.end())return false;

              vector<int>ind=mp[tar];
              for(auto it:ind)        // O(n)
              {
                  string tmp=s;

                  if(it!=i)
                  swap(tmp[i],tmp[it]);
                  if(goal==tmp)return true;
              }
              return false;

            
           }
       }
       if(s==goal)
       {
           for(auto it:mp)
           {
               if(it.second.size()>=2)return true;
           }
       }
       return false;
    }
};

int main()
{
    
    return 0;
}