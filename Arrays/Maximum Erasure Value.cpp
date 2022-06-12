#include<iostream>
#include<vector>
using namespace std;

// Runtime: 317 ms, faster than 80.44% of C++ online submissions for Maximum Erasure Value.
// Memory Usage: 96.4 MB, less than 91.62% of C++ online submissions for Maximum Erasure Value.

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
       
        
        int n=nums.size();
        
         vector<int>prefixSum(n+1,0);
        
        int start=0;
        vector<int>vec1(10001,-1);
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            prefixSum[i+1]=prefixSum[i]+nums[i];
;        }
        
        for(int i=0;i<n;i++)
        {
            start=max(start,vec1[nums[i]]+1);
            ans=max(ans,prefixSum[i+1]-prefixSum[start]);
            vec1[nums[i]]=i;
        }
        
        return ans;
    }
};

int main()
{
    
    return 0;
}