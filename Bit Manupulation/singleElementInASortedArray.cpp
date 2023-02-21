#include<iostream>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int tar=0;
        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            tar^=nums[i];
        }

        return tar;
    }
};

int main()
{
    
    return 0;
}