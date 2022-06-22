#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// using priority queue
// Runtime: 8 ms, faster than 83.25% of C++ online submissions for Kth Largest Element in an Array.
// Memory Usage: 10.5 MB, less than 9.65% of C++ online submissions for Kth Largest Element in an Array.

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        priority_queue<int>que;
        
        for(int i=0;i<n;i++)
        {
            que.push(nums[i]);
        }
        
        int res;
        
        while(k!=1)
        {
            que.pop();
            k--;
        }
        return que.top();
    }
};

int main()
{
    
    return 0;
}