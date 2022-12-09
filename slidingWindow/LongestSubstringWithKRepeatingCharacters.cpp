#include<iostream>
using namespace std;


class Solution {
public:
     
     bool isVerified(string s,int k)
     {
        unordered_map<char,int>mp;

        for(auto it:s)
        mp[it]++;
         for(auto it:mp)
         {
             if(it.second<k)return false;
         }

         return true;
     }

    int longestSubstring(string s, int k) {
        
        int maxLen=INT_MIN;

        int low=0;
        int high=k-1;
         int n=s.length();


      if(k==1){
          int len=s.length();

          return len;
      }
       
      

        while(low<n)
        {
            high=low+(k-1);
            char temp=s[low];
            while(high<n)
            {
                string subst=s.substr(low,(high-low+1));

                int l=subst.length();


               // cout<<subst<<" "<<isVerified(subst,k)<<endl;


               

                if(isVerified(subst,k))
                {
                    int len=high-low+1;
                    maxLen=max(maxLen,len);
                }


                high++;
                
            }

            while(s[low]==temp)
            low++;
        }
        
        if(maxLen==INT_MIN)return 0;
        return maxLen;
    }
};

int main()
{
    
    return 0;
}