#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;

// T(N)=O(26*26*N)
// S(N)=O(1)

class Solution {
public:
    int largestVariance(string s) {
        
        int res=INT_MIN;
        vector<char>vec;
        int n=s.length();
        unordered_map<char,bool>mp;

        for(int i=0;i<n;i++)
        {
            if(mp.find(s[i])==mp.end()){
            vec.push_back(s[i]);
            mp[s[i]]=true;
            }
        }
        for(int i=0;i<vec.size();i++)
        {
            char firstEle=vec[i];
            for(int j=0;j<vec.size();j++)
            {
                if(i!=j){
                char secondEle=vec[j];
                int countFirst=0;
                int countSecond=0;
                bool secondSeenPast=false;
                for(int k=0;k<n;k++)
                {
                    if(s[k]==secondEle)
                    {
                        secondSeenPast=true;
                    }
                     if(s[k]==firstEle)countFirst++;
                     if(s[k]==secondEle)countSecond++;
                   
                    int diff=countFirst-countSecond;
                   
                    if(countSecond>0)
                    {
                        res=max(res,diff);
                    }
                    else{
                        secondSeenPast==true;
                        res=max(res,countFirst-1);
                    }
                     if(diff<0){
                          countFirst=0;
                          countSecond=0;
                     }
                 }
                }
            }
        }
        if(res==INT_MIN)return 0;
        return res;
    }
};

int main()
{
    
    return 0;
}