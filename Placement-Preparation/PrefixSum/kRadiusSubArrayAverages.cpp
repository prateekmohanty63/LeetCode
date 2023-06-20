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
         int r=0;

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
        // for(auto it:preFix)cout<<it<<" ";

        // cout<<endl;

        // for(auto it:suFix)cout<<it<<" ";

        for(int i=0;i<n;i++)
        {
            if(i-k<0){
                res.push_back(-1);
            }
            else if(i+k>=n){
                res.push_back(-1);
            }
            else{
                long long sum=nums[i];
                long long preSum=0;
                long long posSum=0;

                if(i==k){
                    preSum+=(long long)preFix[i-1];
                }
                else{
                    preSum+=(long long)(preFix[i-1]-preFix[r++]);
                }
                if((n-i-1)==k){
                    posSum+=(long long)suFix[i+1];
                }
                else{
                    posSum+=(long long)(suFix[i+1])-suFix[i+k+1];
                }
               // cout<<preSum<<" "<<sum<<" "<<posSum<<endl;
                sum+=preSum+posSum;
                sum/=(2*k+1);
                res.push_back(sum);
            }
        }
        return res;
    }
};

int main()
{
    
    return 0;
}