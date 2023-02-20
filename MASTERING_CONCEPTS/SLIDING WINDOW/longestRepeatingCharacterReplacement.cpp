#include<iostream>
#include<unordered_map>
#include<climits>

using namespace std;


class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int n=s.length();
        
        int start=0,end=0;

        unordered_map<char,int>mp;

        int maxLen=INT_MIN;
        

        while(end<n)
        {
            mp[s[end]]++;

            int maxim=INT_MIN;

            for(auto it:mp)
            {
                maxim=max(maxim,it.second);
            }

            int lenWin=end-start+1;
            
            if(lenWin-maxim<=k)
            {
                maxLen=max(maxLen,end-start+1);
            }
            else{

              int currMaxim=maxim;

              while((end-start+1)-currMaxim>k)
              {
                  mp[s[start]]--;
                  start++;

                  for(auto it:mp)
                  {
                      currMaxim=max(currMaxim,it.second);
                  }
              }
            
            }
             end++;
        }
        int flag=0;
        
        

        return maxLen;

    }
};

int main()
{
    
    return 0;
}