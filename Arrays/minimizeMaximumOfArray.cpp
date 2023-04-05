#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        
        // one thing to note here is that the maxim will never be less than the first element of the array 
        // at any point of time 

        int res=nums[0];

        long long currTotal=nums[0];

        for(int i=1;i<nums.size();i++)
        {
              currTotal+=nums[i];
              int t = ceil (double(currTotal)/double(i+1));
              res=max(res,t);
        }

        return res;
    }
};

int main()
{
    
    return 0;
}