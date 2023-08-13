#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


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