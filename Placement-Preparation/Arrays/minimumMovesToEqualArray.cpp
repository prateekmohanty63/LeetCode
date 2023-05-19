#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



class Solution {
public:
   
   bool isSame(vector<int>&nums)
   {
       int n=nums.size();
      
       for(int i=0;i<n-1;i++)
       {
           if(nums[i]!=nums[i+1])return false;
       }
       return true;
   }

    int minMoves(vector<int>& nums) {
        
        int n=nums.size();
        sort(nums.begin(),nums.end());

        int res=0;

        while(!isSame(nums))
        {
            if(nums[n-2]!=nums[n-1])
            {
                for(int i=0;i<n-1;i++)nums[i]++;
                res++;
            }
            else{
                for(int i=0;i<n-1;i++)nums[i]++;
                res++;
                sort(nums.begin(),nums.end());
            }
        }

     return res;
    }
};

int main()
{
    
    return 0;
}