#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        
        int res=0;

        unordered_map<int,int>mp;

        int n=arr.size();

        for(int i=0;i<n;i++)
        {
            int ele=arr[i]-difference;
            if(mp.find(ele)!=mp.end())
            {
                mp[arr[i]]=mp[ele]+1;
            }
            else{
                mp[arr[i]]=1;
            }
        }

        for(auto it:mp)res=max(res,it.second);

        return res;
    }
};

int main()
{
    
    return 0;
}