#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

// TLE 

class Solution {
public:
    vector<int>res;
    int size=INT_MIN;
    int solve(vector<int>&nums,int ind,int prevNum,vector<int>&vec)
    {
         int n=nums.size();
         if(ind==n-1)
         {   
             if(nums[ind]%prevNum==0)
             {
                 vector<int>vec1=vec;
                 vec1.push_back(nums[ind]);
                 
                 int m=vec1.size();
                 if(m>=size)
                 {
                     size=m;
                     res=vec1;
                 }
             }
             else{
                 int m=vec.size();
                 if(m>=size)
                 {
                     size=m;
                     res=vec;
                 }
             }
             
             return 0;
         }
         

         if(prevNum==-1)
         {
             // we have the option of taking the current element
             // or not taking it
             vector<int>vec1=vec;
             vec1.push_back(nums[ind]);
             return max(1+solve(nums,ind+1,nums[ind],vec1),solve(nums,ind+1,prevNum,vec));
         }
         else{
              // if the current element is a multiple of previous element
              // we have the option of taking it or not taking it

              if(nums[ind]%prevNum==0)
              {
                   vector<int>vec1=vec;
                 vec1.push_back(nums[ind]);
                  return max(1+solve(nums,ind+1,nums[ind],vec1),solve(nums,ind+1,prevNum,vec));
              }

              // if it is not we dont take it
              else 
              return solve(nums,ind+1,prevNum,vec);
         }
 

    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n=nums.size();

        sort(nums.begin(),nums.end());
        vector<int>res1;

        int count=solve(nums,0,-1,res1);
        cout<<count<<" ";

        return res;
    }
};

int main()
{
    
    return 0;
}