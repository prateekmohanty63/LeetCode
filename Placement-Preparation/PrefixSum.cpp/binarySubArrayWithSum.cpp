#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        int n=nums.size();
        int res=0;
        
        int currSum=0;
        unordered_map<int,int>mp;

        mp[0]=1;

        for(int i=0;i<n;i++)
        {
            currSum+=nums[i];
            int numReq=currSum-goal;

            if(mp.find(numReq)!=mp.end())res+=mp[numReq];

            mp[currSum]++;
        }
        return res;
    }
};

int main()
{
    
    return 0;
}