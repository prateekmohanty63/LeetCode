#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;


// T(N)=O(n^2logn)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        int n=strs.size();
        map<string,vector<string>>map1;
        vector<vector<string>>res;
        
        
        for(int i=0;i<n;i++)
        {
            string a=strs[i];
            sort(a.begin(),a.end());
            map1[a].push_back(strs[i]);
        }
        
        map<string,vector<string>>::iterator itr;
        
        for(itr=map1.begin();itr!=map1.end();itr++)
        {
            res.push_back(itr->second);
        }
        return res;
    }
};

int main()
{
    
    return 0;
}