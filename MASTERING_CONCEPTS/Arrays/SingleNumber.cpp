#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int n=nums.size();

        if(n==1)return nums[0];

        int tar=nums[0];

        for(int i=1;i<n;i++)
        {
            tar=tar^nums[i];

            
        }
        return tar;
    }
};

int main()
{
    
    return 0;
}