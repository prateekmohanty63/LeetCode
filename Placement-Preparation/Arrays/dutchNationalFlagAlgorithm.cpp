#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int low=0;
        int mid=0;

        int high=nums.size()-1;

        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[mid],nums[low]);
                mid++;
                low++;
            }
            else if(nums[mid]==1)mid++;

            else if(nums[mid]==2)
            {
                swap(nums[mid],nums[high]);
                high--;
              
            }
        }
    }
};

int main()
{
    
    return 0;
}