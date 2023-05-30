#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n=nums.size();
       sort(nums.begin(),nums.end());

        int flag=0;
        int flag1=0;

        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)flag=1;

            if(nums[i]==n)flag1=1;
        }
        if(flag==0)return 0;
        if(flag1==0)return n;

       for(int i=0;i<n-1;i++)
       {
           if(nums[i+1]-nums[i]!=1)
           {
               return nums[i]+1;
           }
       }

      return n;

    }
};

int main()
{
    
    return 0;
}