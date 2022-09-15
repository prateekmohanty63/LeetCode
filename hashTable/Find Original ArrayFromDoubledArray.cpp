#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<cmath>
using namespace std;

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        
        int n=changed.size();
        
        // if array is not even length then it cannot be a double array
        if(n%2!=0)return {};
        
        vector<int>res;
        
        unordered_map<int,int>mp;
        
        sort(changed.begin(),changed.end());
        
        for(int i=0;i<n;i++)
        {
            mp[changed[i]]++;
        }
        
        int count=0;
        
        // if 0 present in the array (handled)
        if(mp.find(0)!=mp.end())
        {
            int a=mp[0];
            
            if(a%2!=0)return {};
            
            for(int i=0;i<a/2;i++)
            {
                res.push_back(0);
            
            }
        }        
        
        
        for(int i=0;i<n;i++)
        {
            if(changed[i]!=0)
            {
                int a=changed[i];
                
                // a*2 should be present
                // a*2 should not be 0 (if it is 0 we have already used the element)
                // a should not be 0 (if it is 0 we have already used the element)
                
                if(mp.find(a*2)!=mp.end() && mp[a*2]!=0 && mp[a]!=0)
                {
                    res.push_back(a);
                    mp[a*2]--;
                    mp[a]--;
                    
                }
            }
            
            if(res.size()==n/2)break;
             
        }
        
        for(int i=0;i<res.size();i++)cout<<res[i]<<" ";
            
     int b=ceil(n/2);
            
        if(res.size()==b)return res;
            
            return {};
        
        return res;
    }
};

int main()
{
    
    return 0;
}