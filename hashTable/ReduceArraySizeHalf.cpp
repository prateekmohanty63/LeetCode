#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

class Solution {
public:
    
    static bool cmp(pair<int, int>& a,
         pair<int, int>& b)
{
    return a.second > b.second;
}
    int minSetSize(vector<int>& arr) {
        
        map<int,int>freq;
        
        int n=arr.size();
        
        for(int i=0;i<n;i++)freq[arr[i]]++;
        
        vector<pair<int,int>>vecfreq;
        
        for(auto it:freq)
        {
            vecfreq.push_back(it);
        }
        
        sort(vecfreq.begin(),vecfreq.end(),cmp);
        
        
        int temp=n-n/2;
        int res=0;
        
        for(auto it:vecfreq)
        {
            if(temp<=0)break;
            
            temp-=it.second;
            
            res++;
        }
        return res;
    }
};

int main()
{
    
    return 0;
}