#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        
        int n=nums.size();
        int res=0;
        int mod=1000000007;

        int start=0;
        int end=n-1;

        sort(nums.begin(),nums.end());
        vector<int>prePow={1};
        for(int i=1;i<=n;i++)
        {
            prePow.push_back((prePow.back()<<1)%mod);
        }

        while(start<=end)
        {
            int sum=nums[start]+nums[end];

            if(sum>target)
            {
               end--;
            }
            else{
                 res = (res + prePow[end - start]) % mod;
                 start++;
            }
        }
        return res%mod;
    }
};

int main()
{
    
    return 0;
}