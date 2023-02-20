#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        
        int res=0;
        
        unordered_map<int,bool>mp;
        
        for(auto it:banned)
        {
            mp[it]=true;
        }
        
        for(int i=1;i<=n;i++)
        {
            if(mp.find(i)==mp.end())
            {
                if(i<=maxSum)
                {
                    res++;
                    maxSum-=i;
                }
            }
            if(maxSum<i)break;
            
        }
        return res;
    }
};

int main()
{
    
    return 0;
}