#include<iostream>
#include<vector>
using namespace std;


class NumArray {
public:
   vector<int>preSum;

    NumArray(vector<int>& nums) {
         
         preSum=nums;
         for(int i=1;i<nums.size();i++)
         {
             preSum[i]+=preSum[i-1];
         }
    }
    
    int sumRange(int left, int right) {
        
        if(left==0)return preSum[right];

        return preSum[right]-preSum[left-1];
    }
};

int main()
{
    
    return 0;
}