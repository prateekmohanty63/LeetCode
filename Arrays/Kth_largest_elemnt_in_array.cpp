#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;


// using priority queue
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