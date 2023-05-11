#include<iostream>
#include<vector>
#include<deque>
using namespace std;


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int>q;
        vector<int>res;

        for(int i=0;i<nums.size();i++)
        {
            if(q.front()==i-k)
            {
                // left most index is out of bound
                q.pop_front();
            }
           
           // pop left most elements till they are smaller than the current element
            while(!q.empty() && nums[q.back()]<nums[i])
            q.pop_back();

            q.push_back(i);

            if(i>=k-1)res.push_back(nums[q.front()]);
        }
        return res;
    }
};

int main()
{
    
    return 0;
}