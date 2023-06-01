#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        
        int count=0;

        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                long a=(long)2*nums[j];
                if(nums[i]>a)count++;
            }
        }
        return count;
    }
};

int main()
{
    
    return 0;
}