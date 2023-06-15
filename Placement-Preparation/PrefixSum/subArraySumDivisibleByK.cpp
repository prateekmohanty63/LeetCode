#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        // calulating the prefix sum
        int res=0;
        int n=nums.size();

        vector<int>preFixSum(n,0);

        preFixSum[0]=nums[0];

        for(int i=1;i<n;i++){
            preFixSum[i]=preFixSum[i-1]+nums[i];
        }

        for(int i=0;i<n;i++)
        {
             int a=preFixSum[i];
             if(a%k==0)res++;

            for(int j=i+1;j<n;j++)
            {
                int b=preFixSum[j];

                if(abs(a-b)%k==0)res++;
            }
        }
        return res;
    }
};

int main()
{
    
    return 0;
}