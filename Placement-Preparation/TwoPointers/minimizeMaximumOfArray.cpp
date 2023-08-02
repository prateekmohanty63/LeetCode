#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        
        int n=nums.size();

        sort(nums.begin(),nums.end());

        int start=0;
        int end=nums.size()-1;
        int res=INT_MIN;

        while(start<end)
        {
            int sum=nums[start]+nums[end];
            res=max(res,sum);
            start++;
            end--;
        }
        return res;
    }
};

int main()
{
    
    return 0;
}