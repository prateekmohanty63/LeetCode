#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {

       int n=names.size();
       unordered_map<string,int>mp;

       vector<string>res;

       for(int i=0;i<n;i++)
       {
           string name=names[i];

           if(mp.find(name)==mp.end())
           {
               res.push_back(name);
               mp[name]=1;
           }
           else{
              
              int currFile=mp[name];
              string newFileName=name+"("+to_string(currFile)+")";

              while(mp.find(newFileName)!=mp.end())
              {
                  currFile++;
                  mp[name]++;
                  newFileName=name+"("+to_string(currFile)+")";
              }

              res.push_back(newFileName);
              mp[newFileName]=1;
       }  
       } 

       return res;
    }
};

int main()
{
    
    return 0;
}