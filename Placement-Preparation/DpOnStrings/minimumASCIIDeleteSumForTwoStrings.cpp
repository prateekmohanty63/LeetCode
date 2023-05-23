#include<iostream>
#include<set>
#include<climits>
#include<unordered_map>
using namespace std;


// TLE

class Solution {
public:

    set<string>vec;

    int maxSubSequence(string s1,string s2,int i,int j,string res)
    {
        int n=s1.length();
        int m=s2.length();

        if(i>=n || j>=m)
        {   
            vec.insert(res);
            return 0;
        }

        if(s1[i]==s2[j])
        {
          
            return 1+maxSubSequence(s1,s2,i+1,j+1,res+s1[i]);
        }
        else{
            return max(maxSubSequence(s1,s2,i+1,j,res),maxSubSequence(s1,s2,i,j+1,res));
        }
    }
    int minimumDeleteSum(string s1, string s2) {
        
        
        if(s1==s2)return 0;
        set<string>vec1;

        int res=INT_MAX;
        
        int a=maxSubSequence(s1,s2,0,0,"");
        
        for(auto it:vec)
        {
            if(it.length()==a)vec1.insert(it);
        }
        for(auto it:vec1)
        {
            cout<<it<<" ";
            unordered_map<char,int>mp;
            string a=it;
            int count=0;
            for(int i=0;i<a.length();i++)
            {
                mp[a[i]]+=2;
            }
            for(int i=0;i<s1.length();i++)
            {
                if(mp.find(s1[i])==mp.end())
                {
                    count+=int(s1[i]);
                }
                else if(mp.find(s1[i])!=mp.end())
                {
                    if(mp[s1[i]]==0)count+=int(s1[i]);

                    else mp[s1[i]]--;
                }
            }

              for(int i=0;i<s2.length();i++)
            {
                if(mp.find(s2[i])==mp.end())
                {
                    count+=int(s2[i]);
                }
                else if(mp.find(s2[i])!=mp.end())
                {
                    if(mp[s2[i]]==0)count+=int(s2[i]);

                    else mp[s2[i]]--;
                }
            }
            res=min(res,count);
        }

        return res;

    }
};

int main()
{
    
    return 0;
}