#include<iostream>
#include<unordered_map>
#include<climits>

using namespace std;


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    bool isSame(unordered_map<char,int>&orgMap,unordered_map<char,int>&currMp)
    {
        for(auto it:orgMap)
        {
             if(currMp[it.first]<it.second)return false;
        }
        return true;
    }
    string smallestWindow (string s, string p)
    {
        // Your code here
        
        int n=s.length();
        int m=p.length();
        if(n<m)return "-1";
        if(n==m && s!=p)return "-1";
        else if(n==m && s==p)return p;
        
        int res=INT_MAX;
        string strRes;
        int startInd;
        
        vector<int>orgFreq(26,0);
        
        for(auto it:p)
        {
            orgFreq[it-'a']++;
        }
        
        int r=0;
        
        int start=0;
        int end=0;
        
        while(end<n)
        {
            // check how many elements remains to be taken of the given char
            if(--orgFreq[s[end++]-'a']>=0)r++;
            
            while(r==m)
            {
                if(end-start<res)
                {
                    res=end-start;
                    startInd=start;
                }
                // now increase the count of element to be taken , because we are removing s[start] from window
                if(++orgFreq[s[start++]-'a']>0)r--;
            }
          
        }
        
        
        
        if(res==INT_MAX)return "-1";
        strRes=s.substr(startInd,res);
        
        return strRes;
    }
};

// } Driver Code Ends

class Solution {
public:
    
    bool isValid(unordered_map<char,int>&currMap,unordered_map<char,int>&target)
    {
        for(auto it:target){
              int freq=it.second;

              if(currMap[it.first]<freq)return false;
        }
        return true;
    }
 
    string minWindow(string s, string t) {
        
        int n=s.length();
        int m=t.length();

       

        if(n<m)return "";

        int minLen=INT_MAX;
        string res;

        unordered_map<char,int>mp;

        for(int i=0;i<m;i++)mp[t[i]]++;

        int start=0;
        int end=start+m-1;

        unordered_map<char,int>currMp;

        for(int i=start;i<=end;i++){
            if(mp.find(s[i])!=mp.end())
            currMp[s[i]]++;
        }

        if(m==1){
            unordered_map<char,int>freq;
            for(auto it:s)freq[it]++;

            if(freq.find(t[0])!=freq.end())return t;

            else return "";
        }
       // for(auto it:currMp)cout<<it.first<<" "<<it.second<<endl;
       
        while(end<n)
        {
             if(isValid(currMp,mp))
             {
                 while(start<end && isValid(currMp,mp))
                 {
                    // cout<<start<<" "<<end;
                     if(mp.find(s[start])!=mp.end()){
                           currMp[s[start]]--;
                     }
                     start++;
                 }
                 int len=end-start+2;
                 if(len<minLen)
                 {
                     minLen=len;
                     cout<<start<<" "<<len<<endl;
                    // if(start-1>=0)
                     res=s.substr(start-1,len);

                    // else res=s.substr(start,len);
                 }
             }
             end++;
             if(end<n)
             {
                 if(mp.find(s[end])!=mp.end())currMp[s[end]]++;
             }
        }
        return res;

    }
};

int main()
{
    
    return 0;
}