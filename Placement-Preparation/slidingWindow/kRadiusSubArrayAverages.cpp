#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        
        vector<int>res;

        if(k==0){
            return nums;
        }

        int n=nums.size();
         

        vector<long long>preFix(n,0);
        vector<long long>suFix(n,0);

        preFix[0]=nums[0];

        for(int i=1;i<n;i++){
            preFix[i]=(long long)preFix[i-1]+nums[i];
        }

        suFix[n-1]=nums[n-1];

        for(int i=n-2;i>=0;i--){
            suFix[i]=(long long)suFix[i+1]+nums[i];
        }
        long long slidingWindowSumStart=0;
        long long slidingWindowSumEnd=0;
       int r=0;
        int m=k+1;
        for(int i=0;i<n;i++)
        {
            if(i-k<0){
                res.push_back(-1);
            }
            else if(i+k>=n){
                res.push_back(-1);
            }
            else{
                long long sum=(long long)(slidingWindowSumStart+nums[i]+slidingWindowSumEnd);
                sum/=(2*k+1);
                slidingWindowSumStart-=nums[r++];
                slidingWindowSumEnd-=nums[m++];

                res.push_back(sum);

            }
            slidingWindowSumStart+=nums[i];
            if(k+1+i<n)
            slidingWindowSumEnd+=nums[k+1+i];
        }
        return res;
    }
};

int main()
{
    
    return 0;
}