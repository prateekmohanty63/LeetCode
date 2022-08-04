#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int maxSum=INT_MIN;
        
        int n=nums.size();
        
        int sum=0;
        
        for(int i=0;i<n;i++)
        {
            
            if(sum<0)sum=0;
            
            sum+=nums[i];
            
             maxSum=max(sum,maxSum);
        }
        return maxSum;
    }
};

int main()
{
    return 0;
}