#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:
    
    bool checkSubstring(unordered_map<string, int> wordCount, string s, int wordLen) {
        for(int j=0; j<s.size(); j+=wordLen) {
            string w = s.substr(j, wordLen);
            if(wordCount.find(w) != wordCount.end()) {
                if(--wordCount[w] == -1) {
                    return false;
                }
            } else {
                return false;
            }
        }
        return true;
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int wordLen = words[0].size();
        int sLen = s.size();
        int wordsWindow = words.size() * wordLen;
        
        unordered_map<string, int> wordCount;
        for(int i=0; i<words.size(); i++) {
            wordCount[words[i]]++;
        }
        
        int i = 0;
        while(i + wordsWindow <= sLen) {
            if(checkSubstring(wordCount, s.substr(i, wordsWindow), wordLen)) {
                res.push_back(i);
            }
            i++;
        }
        return res;
    }
};


class Solution {
public:
    vector<int> findSubstring(string S, vector<string>& words) {
        
        int n=S.length();
        int l=words.size();
        int m=words[0].size();

        vector<int>ind;

      //  if(n<l*m)return ind;
        if(l==0 || n==0)return ind;
         unordered_map<string,int>wordCount;
         vector<int>res;

         for(auto word:words)
         wordCount[word]++;
         

         int start=0;
         int end=words.size()*m-1;
         
         while(end<n)
         {
             unordered_map<string,int>tempMap;
             int s=start;
             int e=s+(m-1);
             int flag=0;

             while(e<=end)
             {
                 string substr=S.substr(s,e-s+1);
                
                 if(wordCount.find(substr)!=wordCount.end()){
                     int freq=wordCount[substr];
                     int currFreq=tempMap[substr];
                     if(currFreq>=freq)
                     {
                         flag=1;
                         break;
                     }
                     else{
                         tempMap[substr]++;
                     }
                 }
                 else break;
                 s=e+1;
                 e+=m;
             }
             if(flag==0)res.push_back(start);

             start++;
             end++;

         }
         return res;
    }
};

// TLE 

class Solution {
public:
    vector<int>res;
    unordered_map<string,bool>mp;
    vector<int> findIndices(string s,string target)
    {
        int start=0;
        int end=target.size()-1;
        int n=s.length();
        int m=target.size();

        if(m>n)return {};
        else if(m==n)
        {
            if(s==target)return {0};
            else return {};
        }
        vector<int>res;

        while(end<n)
        {
             string substr=s.substr(start,end-start+1);
             if(substr==target)
             {
                 res.push_back(start);
             }
             start++;
             end++;
        }
        return res;
    }

    void solve(string &s,vector<string>&words,string curr,vector<bool>&used)
    {
         if(curr.size()==words.size()*words[0].size())
         {
             if(mp.find(curr)==mp.end()){
             vector<int>vec=findIndices(s,curr);
             mp[curr]=true;
             for(auto it:vec)res.push_back(it);
             }
             
             
         }

         for(int i=0;i<words.size();i++)
         {
             if(!used[i])
             {
                 used[i]=true;
                 solve(s,words,curr+words[i],used);
                 used[i]=false;
             }
         }
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        
        int n=words.size();
        vector<bool>used(n,false);
        solve(s,words,"",used);

        return res;
    }
};

int main()
{
    
    return 0;
}