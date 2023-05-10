#include<iostream>
#include<vector>
#include<climits>
#include<unordered_map>
using namespace std;


class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int n=nums.size();
        int maxLen=INT_MIN;

        int start=0;
        int end=0;

        unordered_map<int,int>mp;

        while(end<n)
        {
            mp[nums[end]]++;

            if(mp.find(0)==mp.end())
            {
                 maxLen=max(maxLen,end-start+1);
            }

           else
            {
                if(mp[0]>k)
                {
                    while(mp[0]>k)
                    {
                        mp[nums[start]]--;
                        start++;
                    }
                }
                else{
                     maxLen=max(maxLen,end-start+1);
                }
            }
           
            end++;
        }
        if(maxLen==INT_MIN)return 0;
        return maxLen;
    }
};

int main()
{
    
    return 0;
}