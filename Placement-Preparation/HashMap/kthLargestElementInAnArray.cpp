#include<iostream>
#include<queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
         
        priority_queue<int,vector<int>,greater<int>>pq;   // min heap

        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            pq.push(nums[i]);

            if(pq.size()>k)pq.pop();
        }

        return pq.top();
    }
};

int main()
{
    
    return 0;
}