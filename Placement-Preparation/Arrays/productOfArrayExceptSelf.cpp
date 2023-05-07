#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n=nums.size();

        vector<int>prefixMul(n,1),suffixMul(n,1);
        vector<int>res(n,1);

        int prod1=1,prod2=1;

        for(int i=0;i<n;i++)
        {
            prod1*=nums[i];
            prefixMul[i]=prod1;
        }
        int k=0;

        for(int i=n-1;i>=0;i--)
        {
            prod2*=nums[i];
            suffixMul[k++]=prod2;
        }
       
        res[0]=suffixMul[n-2];
        res[n-1]=prefixMul[n-2];

        for(int i=1;i<n-1;i++)
        {
            int prod=prefixMul[i-1]*suffixMul[n-(i+2)];
            res[i]=prod;
        }

        return res;

    }
};

int main()
{
    
    return 0;
}