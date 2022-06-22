#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



// 32 / 32 test cases passed.
// Status: Accepted
// Runtime: 12 ms
// Memory Usage: 9.9 MB

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        sort(nums.begin(),nums.end(),greater<int>());
        int i=0;
        
         
        return nums[k-1];
        
        
    }
};

int main()
{
    
    return 0;
}