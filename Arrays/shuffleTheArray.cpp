#include<iostream>
using namespace std;


class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        vector<int>res;

        int ptr1=0;
        int ptr2=n;

        for(int i=0;i<n;i++)
        {
            res.push_back(nums[ptr1++]);
            res.push_back(nums[ptr2++]);
        }

        return res;
    }
};

int main()
{
    
    return 0;
}