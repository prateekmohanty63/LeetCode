class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size()/2;
        int count=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                count++;
                if(count+1>n)
                    return nums[i];
            }
            else
                count=0;
        }
        return nums[0];
    }
};
