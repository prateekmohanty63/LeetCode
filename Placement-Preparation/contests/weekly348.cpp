#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


// minimum string left
class Solution {
public:
    int minimizedStringLength(string s) {
        
        int n=s.length();
        
       vector<char>vec;
        unordered_map<char,bool>mp;
        
        
        for(int i=0;i<n;i++)
        {
            char currChar=s[i];
            if(mp.find(currChar)==mp.end())
            {
                vec.push_back(currChar);
                mp[currChar]=true;
            }
        }
        return mp.size();
    }
};

int main()
{
    
    return 0;
}