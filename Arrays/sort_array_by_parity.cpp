#include<iostream>
#include<vector>
using namespace std;


// 1st method
// Runtime: 10 ms, faster than 82.44% of C++ online submissions for Sort Array By Parity.
// Memory Usage: 16.5 MB, less than 12.17% of C++ online submissions for Sort Array By Parity.

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        int n=nums.size();
        
        if(n==1)return nums;
        
        vector<int>res;
        
        for(int i=0;i<n;i++)
        {
            int a=nums[i];
            
            if(a%2==0)
            {
                res.push_back(a);
            }
        }
        for(int i=0;i<n;i++)
        {
            int a=nums[i];
            
            if(a%2!=0)
            {
                res.push_back(a);
            }
        }
        return res;
    }
};

int main()
{
    
    return 0;
}