// First approach
// O(N) time complexity O(1) space complexity


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int a;
        if(nums.size()==1)
            return nums[0];
        for(int i=0;i<nums.size()-1;i+=2){
            if(nums[i]!=nums[i+1]){
                a=nums[i];
                return nums[i];
            }
        }
        return nums[nums.size()-1];
    }
};


// Xor operation
// xor of same numbers is 0 hence we will get the element which is not duplicate
// O(n) time complexity and O(1) space complexity

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int xr{};

        for(auto num: nums)
            xr = xr^num;

        return xr;
    }
};

/// binary search

