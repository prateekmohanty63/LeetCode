#include<iostream>
using namespace std;


// T(N)=O(N^2)
// S(N)=O(1)
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        // sorting the nums
        sort(nums.begin(),nums.end());

        int res=1;
        int n=nums.size();
        
        for(int i=1;i<n;i++)
        {
            int count=1;
            int ele=nums[i];
            int tempK=k;

            for(int j=i-1;j>=0;j--)
            {
                if(ele-nums[j]<=tempK){
                    count++;
                    tempK-=(ele-nums[j]);
                }
                else break;
            }
            res=max(res,count);
        }
       return res;
    }
};

int main()
{
    
    return 0;
}