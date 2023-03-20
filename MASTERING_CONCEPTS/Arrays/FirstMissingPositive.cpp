#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n=nums.size();

        unordered_map<int,bool>mp;

        int minim=INT_MAX;
        int maxim=INT_MIN;

        for(int i=0;i<n;i++)
        {
           minim=min(nums[i],minim);
           maxim=max(nums[i],maxim);
           mp[nums[i]]=true;
        }

        if(maxim<=0)return 1;

        for(int i=1;i<=maxim;i++)
        {
            if(mp.find(i)==mp.end())return i;
        }
        return maxim+1;
    }
};

int main()
{
    
    return 0;
}