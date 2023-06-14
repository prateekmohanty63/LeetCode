#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        
        int n=arr.size();
        vector<int>vec(n+1,0);
        unordered_map<int,int>mp;

        for(int i=0;i<n;i++)
        {
            int currEle=arr[i];
            int prevEle=arr[i]-difference;

            if(mp.find(prevEle)==mp.end())
            {
               vec[i]=1;
            }
            else{
              // element was already present in the array
              // add that index result into current index
              int indFound=mp[prevEle];
              vec[i]=vec[indFound]+1;
            }
            mp[arr[i]]=i;
        }

        int res=0;

        for(auto it:vec)
        {
            res=max(res,it);
            cout<<it<<" ";
        }
        return res;
    }
};

int main()
{
    
    return 0;
}