#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;



class Solution {
public:

  static bool cmp(pair<char, int>& a,
         pair<char, int>& b)
{
    return a.second > b.second;
}
 
    string frequencySort(string s) {
             
             unordered_map<char,int>mp;

             int n=s.length();


             for(int i=0;i<n;i++)
             {
                 mp[s[i]]++;
             }

             vector<pair<char,int>>vec1;

             for(auto it:mp)
             {
                 vec1.push_back(it);
             }
        
        sort(vec1.begin(),vec1.end(),cmp);

        string res;

        for(auto it:vec1)
        {
            for(int i=0;i<it.second;i++)
            {
                res+=it.first;
            }
        }
        return res;
    }
};

int main()
{
    
    return 0;
}