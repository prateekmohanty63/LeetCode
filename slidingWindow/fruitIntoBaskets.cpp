#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int n=fruits.size();

        if(n<2)return n;

        int start=0;
        int end=1;
        int res=2;
        unordered_map<int,bool>mp;

        mp[fruits[start]]=true;
        mp[fruits[end]]=true;
        end++;

        while(end<n)
        {
            if(mp.find(fruits[end])!=mp.end())
            {
                end++;
                //res=max(res,((end-start)+1));
            }
            else{
                if(mp.size()<2)
                {
                    mp[fruits[end]]=true;
                    end++;
                }
                else{
                    res=max(res,((end-start)));
                    mp.clear();
                    int currStart=fruits[start];
                    while(fruits[start]==currStart)
                    start++;
                    mp[fruits[start]]=true;
                    end=start+1;
                }
                
            }
        }

        res=max(res,((end-start)));
        
        return res;
    }
};

int main()
{
    
    return 0;
}