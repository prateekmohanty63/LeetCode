#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;


class Solution {
public:
    int minDeletions(string s) {
        
        unordered_map<char,int>mp;
        int res=0;

        for(auto it:s)
        {
            mp[it]++;
        }

       

        vector<int>vec;

        for(auto it:mp)
        {
            vec.push_back(it.second);
        }

        sort(vec.begin(),vec.end(),greater<int>());

        int cutOffFreq=vec[0];

        for(int i=0;i<vec.size();i++)
        {
            if(vec[i]>cutOffFreq)
            {
               if(cutOffFreq>0)res+=(vec[i]-cutOffFreq);

               else res+=vec[i];
            }
            cutOffFreq=min(cutOffFreq-1,vec[i]-1);
        }
        

        return res;
    }
};

int main()
{
    
    return 0;
}