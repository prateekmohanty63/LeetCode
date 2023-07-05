#include<iostream>
#include<vector>
using namespace std;

// T(N)=O(N)
// S(N)=O(1)

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int n=nums.size();

        int start=0;
        int end=0;
        int res=0;
        int noZeros=0;

        while(end<n)
        {
           if(nums[end]==0)noZeros++;

           if(noZeros>1)
           {
               while(start<end && nums[start]!=0)start++;
               start++;
               noZeros--;
           }
           res=max(res,end-start);
            end++;
        }
        return res;
    }
};

int main()
{
    
    return 0;
}