#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int start=0;
        int end=1;
        int n=nums.size();

        int res=0;
        int currProd=nums[start];

        while(end<n)
        {
            currProd*=nums[end];

            if(currProd<k){
                res+=(end-start);
            }
            else{
                while(start<end && currProd>=k){
                    currProd/=nums[start];
                    start++;
                }
                res+=(end-start);
            }
            end++;
        }
        for(auto it:nums)res+=(it<k);
        return res;
    }
};

int main()
{
    
    return 0;
}

