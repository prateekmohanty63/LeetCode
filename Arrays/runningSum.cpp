#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
        vector<int>vec1;
        
        int n=nums.size();
        int sum=0;
        
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            vec1.push_back(sum);
        }
        return vec1;
    }
};

int main()
{
    
    return 0;
}