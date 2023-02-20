#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        // Floyd's cycle detection

        // move the slow  pointer by 1 point
        // move the fast pointer by 2 points

        int slow=nums[0];
        int fast=nums[0];

        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);

        fast=nums[0];

        // now take fast pointer to start of list
        // move slow and fast by 1 point till they are not equal

        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[fast];
        }
       return slow;

    }
};


int main()
{
    
    return 0;
}