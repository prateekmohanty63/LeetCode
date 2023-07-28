#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>

using namespace std;


class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        
        int count=0;
        vector<int>v(60,0);
        int n=time.size();

        for(int i=0;i<n;i++)
        {
            int a=time[i]%60;

            if(a==0)
            count+=v[a];

            else{
                count+=v[60-a];
            }
            v[a]++;
        }
        return count;
    }
};


class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        
        unordered_map<int,int>mp;
        map<pair<int,int>,bool>taken;
        
        int n=time.size();
        long long res=0;


        for(int i=0;i<time.size();i++)
        {
            mp[time[i]]++;
        }

        for(int i=0;i<n;i++)
        {
            int currEle=time[i];

            for(int j=60;j<=1000;j+=60)
            {
                if(j%60==0)
                {
                    if((j-currEle)>=0)
                    {
                        int eleNeeded=j-currEle;

                        if(eleNeeded==currEle)
                        {
                            if(mp.find(eleNeeded)!=mp.end()){
                            int freq=mp[eleNeeded];
                            pair<int,int>pr;
                            pr.first=eleNeeded;
                            pr.second=eleNeeded;

                            if(taken.find(pr)==taken.end()){
                              res+=((long long)freq*((long long)freq-1))/2;
                              taken[pr]=true;
                            }
                        }
                            
                        }
                        else{
                            if(mp.find(eleNeeded)!=mp.end())
                            {
                                pair<int,int>pr;
                                if(eleNeeded<currEle)
                                {
                                    pr.first=eleNeeded;
                                    pr.second=currEle;
                                }
                                else{
                                    pr.first=currEle;
                                    pr.second=eleNeeded;
                                }
                                if(taken.find(pr)==taken.end()){
                               res+=((long long)mp[eleNeeded]*(long long)mp[currEle]);
                               taken[pr]=true;
                                }
                            }
                        }
                    }
                }
            }
            // int k=i;
            // while(k<n && time[k]==currEle)k++;
            // i=k-1;
        }
      
        return res;
    }
};

int main()
{
    
    return 0;
}