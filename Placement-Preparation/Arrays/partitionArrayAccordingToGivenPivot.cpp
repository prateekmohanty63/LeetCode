#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        
        vector<int>lessThan;
       int equalTo=0;
       vector<int>greaterThan;

       for(int i=0;i<nums.size();i++)
       {
           if(nums[i]<pivot)
           {
               lessThan.push_back(nums[i]);
           }
           else if(nums[i]==pivot)equalTo++;
           else greaterThan.push_back(nums[i]);
       }
       int k=0;
       for(auto it:lessThan)
       nums[k++]=it;

       for(int i=0;i<equalTo;i++)
       nums[k++]=pivot;

       for(auto it:greaterThan)
       nums[k++]=it;

       return nums;
    }
};

int main()
{
    
    return 0;
}