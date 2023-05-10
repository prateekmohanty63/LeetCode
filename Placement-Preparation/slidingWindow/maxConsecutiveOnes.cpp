#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int maxLen=INT_MIN;

        int n=nums.size();

        int start=0;
        int end=0;

        while(end<n)
        {
            if(nums[end]==1)
            {
                maxLen=max(maxLen,end-start+1);
            }
            else{
                start=end+1;
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