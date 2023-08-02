#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        
        int res=0;
        int n=nums.size();

        int k=1;

        while(k<n)
        {
            for(int i=0;i<n-k;i++)
            {
                nums[i]=(nums[i]+nums[i+1])%10;
            
            }
            k++;
        }
        
     
        return nums[0];
    }
};

int main()
{
    
    return 0;
}