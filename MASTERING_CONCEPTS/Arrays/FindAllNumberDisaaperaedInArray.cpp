#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>res;

        for(int i=0;i<n;i++)
        {
            int num=abs(nums[i]);

            if(nums[num-1]<0)continue;

            else nums[num-1]=-1*nums[num-1];
        }

        for(auto it:nums)
        cout<<it<<" ";

        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)res.push_back(i+1);
        }

        return res;
    }
};

int main()
{
    
    return 0;
}