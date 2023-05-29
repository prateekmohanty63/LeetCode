#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        int n=s.length();
        stack<char>stk;

        unordered_map<char,int>freq,seen;

        for(int i=0;i<n;i++)
        {
            freq[s[i]]++;
            seen[s[i]]=false;
        }

       

        for(int i=0;i<n;i++)
        {
            // if already present in stack , dont included it 
            if(seen[s[i]]==true)
            {
                freq[s[i]]--;
                continue;
            }
              
              // pop larger elements till possible and stop if frequency of pop element in 0
            while(!stk.empty() && stk.top()>s[i] && freq[stk.top()]>0){
              seen[stk.top()]=false;       
               stk.pop();
            }
            
            stk.push(s[i]);
            seen[s[i]]=true;
            freq[s[i]]--;

        }
           string res;
        while(!stk.empty())
        {
            res+=stk.top();
            stk.pop();
        }
      reverse(res.begin(),res.end());
      return res;
    }
};

int main()
{
    
    return 0;
}