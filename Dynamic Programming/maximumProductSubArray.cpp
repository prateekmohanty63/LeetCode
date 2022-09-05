#include<iostream>
#include<vector>

using namespace std;


//  brute force
// TLE


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int maxRes=INT_MIN;
        
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            int res=nums[i];
            for(int j=i+1;j<n;j++)
            {
                res*=nums[j];
                maxRes=max(maxRes,res);
            }
            maxRes=max(maxRes,nums[i]);
        }
        
        return maxRes;
    }
};

int main()
{
    
    return 0;
}