#include<iostream>
#include<unordered_map>
using namespace std;

// passed all testcases

class Solution {
public:
    int longestSubstring(string s, int k) {
        
        int n=s.length();

        if(n==0 || k>n)return 0;

        if(k==1)return n;

        unordered_map<char,int>mp;

        for(auto it:s)
        {
            mp[it]++;
        }

        int low=0;

        while(low<n && mp[s[low]]>=k)
        {
            low++;
        }

     if(low>=n-1)return low;

     // split the string

     int r1=longestSubstring(s.substr(0,low),k);


    while(low<n && mp[s[low]]<k)low++;

    int l1;
       
       if(low<n)
       l1=longestSubstring(s.substr(low),k);
       else l1=0;

       return max(r1,l1);


    }
};

// TLE

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