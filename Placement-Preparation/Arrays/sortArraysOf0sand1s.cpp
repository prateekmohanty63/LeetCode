#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();

        int k=0;

        // sorting the 0 values first
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                swap(nums[i],nums[k]);
                k++;
            }
        }

        // sorting the 1 values next
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                swap(nums[i],nums[k]);
                k++;
            }
        }

        // sorting the 2 values next
        for(int i=0;i<n;i++)
        {
            if(nums[i]==2)
            {
                swap(nums[i],nums[k]);
                k++;
            }
        }
    }
};

int main()
{
    
    return 0;
}