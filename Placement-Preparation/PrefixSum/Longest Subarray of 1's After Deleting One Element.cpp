#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>preFix;

        int noOnes=0;
        int countZero=0;

        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                preFix.push_back(noOnes);
                noOnes=0;
                countZero++;
            }
            else{
                noOnes++;
            }
        }

        if(countZero==0)return n-1;

         noOnes=0;
         vector<int>suFix(countZero,0);
         int k=countZero-1;

        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]==0)
            {
                suFix[k]=noOnes;
                noOnes=0;
                k--;
            }
            else{
                noOnes++;
            }
        }
        int res=0;

        for(int i=0;i<countZero;i++)
        {
            int count=preFix[i]+suFix[i];
            res=max(res,count);
        }
        return res;
    }
};

int main()
{
    
    return 0;
}