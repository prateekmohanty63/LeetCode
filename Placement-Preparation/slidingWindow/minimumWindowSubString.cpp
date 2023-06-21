#include<iostream>
#include<unordered_map>
#include<climits>

using namespace std;

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