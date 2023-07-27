#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// T(N)=O(N)
// S(N)=O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int sum=0;
        int maxSum=INT_MIN;

        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            maxSum=max(maxSum,sum);
            if(sum<0)sum=0;
        }
        return maxSum;
    }
};

int main()
{
    
    return 0;
}