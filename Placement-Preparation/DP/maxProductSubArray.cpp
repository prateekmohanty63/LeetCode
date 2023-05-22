#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n=nums.size();
        int prod=1;
        int flag=0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]<=0)flag=1;
            prod*=nums[i];
        }

        if(flag==0)return prod;

        int res=INT_MIN;

        for(int i=0;i<n;i++)
        {
            int prod=nums[i];
            if(prod>res)res=prod;

            int k=i+1;
            while(k<n)
            {
                prod*=nums[k];
                if(prod>res)res=prod;
                k++;

            }
        }
        return res;
    }
};

int main()
{
    
    return 0;
}