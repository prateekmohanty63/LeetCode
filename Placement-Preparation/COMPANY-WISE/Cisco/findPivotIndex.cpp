#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int n=nums.size();
        if(n==1)return 0;

        vector<int>preFix(n,0);
        vector<int>suFix(n,0);

        preFix[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            preFix[i]=preFix[i-1]+nums[i];
        }

        suFix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suFix[i]=nums[i]+suFix[i+1];
        }

        for(int i=0;i<n;i++)
        {
            int leftSum,rightSum;
            if(i==0){
                leftSum=0;
                rightSum=suFix[i+1];
            }
         else if(i==n-1){
                rightSum=0;
                leftSum=preFix[i-1];
            }

            else{
               leftSum=preFix[i-1];
               rightSum=suFix[i+1];
            }
            if(leftSum==rightSum)return i;
        }
        return -1;
    }
};

int main()
{
    
    return 0;
}