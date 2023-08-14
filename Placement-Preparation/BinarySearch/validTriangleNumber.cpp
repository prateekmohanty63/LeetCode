#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    
    int binSearch(vector<int>&nums,int target,int s)
    {
        int n=nums.size();
        int start=s;
        int end=n-1;
        int ind=-1;

        while(start<=end)
        {
            int mid=start+(end-start)/2;

            if(nums[mid]<target)
            {
                ind=mid;
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return ind;
    }
    
    int triangleNumber(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int res=0;

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int sum=nums[i]+nums[j];
                int ind=binSearch(nums,sum,j+1);
                if(ind!=-1)
                res+=(ind-j);
            }
        }
        return res;
    }
};

int main()
{
    
    return 0;
}