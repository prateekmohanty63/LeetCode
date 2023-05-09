#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
      
       // set<vector<int>>set1;
        vector<vector<int>>res;

          if(n<3)return res;

        for(int i=0;i<n-2;i++)
        {

          if(i==0 || (i>0 && nums[i]!=nums[i-1])){
            int ptr1=i+1;
            int ptr2=n-1;

            while(ptr1<ptr2)
            {
                 int sum=nums[i]+nums[ptr1]+nums[ptr2]; 

                 if(sum==0)
                 {
                     vector<int>vec;
                     vec.push_back(nums[i]);
                     vec.push_back(nums[ptr1]);
                     vec.push_back(nums[ptr2]);
                     res.push_back(vec);
                     
                     while(ptr1<ptr2 && nums[ptr1]==nums[ptr1+1])ptr1++;
                     while(ptr1<ptr2 && nums[ptr2]==nums[ptr2-1])ptr2--;

                     ptr1++;
                     ptr2--;
                 }

                 else if(sum>0)
                 {
                     ptr2--;
                 }
                 else ptr1++;

            }
         
          }

        }
        return res;
    }
};


class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        
        int sum=0;
        int n=mat.size();
        int m=mat[0].size();

        for(int i=0;i<n;i++)
        {
            sum+=mat[i][i];
        }

        for(int i=0;i<n;i++)
        {
            sum+=mat[i][n-1-i];
        }

        if(n%2==1)
        {
            sum-=mat[n/2][n/2];
        }

        return sum;
    }
};

int main()
{
    
    return 0;
}
