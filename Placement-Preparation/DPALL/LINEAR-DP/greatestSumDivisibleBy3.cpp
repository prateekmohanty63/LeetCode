#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int maximSum=INT_MIN;
    void maxSum(vector<int>&nums,int i,int sum)
    {
        // base case
        int n=nums.size();

        // cout<<sum<<" ";
        
        if(sum%3==0)
         maximSum=max(maximSum,sum);

        if(i>=n)return ;
    

        maxSum(nums,i+1,sum+nums[i]);
        maxSum(nums,i+1,sum);

    }
    
    int maxSumDivThree(vector<int>& nums) {
        
        int n=nums.size();

        maxSum(nums,0,0);

        return maximSum;
    }
};

int main()
{
    
    return 0;
}