#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// better code
class Solution {
public:
   bool isPresent(vector<int>&nums,int i,int sum,vector<vector<int>>&dp)
   {
       // base case
       int n=nums.size();

       if(i>=n)return false;

       if(sum==0)return true;

       if(dp[sum][i]!=-1)return dp[sum][i];

       if(nums[i]<=sum)
       return dp[sum][i]=isPresent(nums,i+1,sum-nums[i],dp) || isPresent(nums,i+1,sum,dp);

       else return dp[sum][i]=isPresent(nums,i+1,sum,dp);
   }
    bool canPartition(vector<int>& nums) {
        
        int n=nums.size();
        int sum=0;

        for(int i=0;i<n;i++)sum+=nums[i];

        if(sum%2!=0)return false;

        vector<vector<int>>dp(sum,vector<int>(n,-1));

        return isPresent(nums,0,sum/2,dp);

    }
};


class Solution {
public:

    char binSearch(vector<char>&letters,char target)
    {
        int n=letters.size();
        int start=0;
        int end=letters.size()-1;
        char closestChar=letters[0];
        int closestDiff=INT_MAX;

        while(start<=end)
        {
            int mid=start+(end-start)/2;

            if(letters[mid]==target)
            {
                if(mid+1<n && letters[mid+1]!=letters[mid])return letters[mid+1];
               else start=mid+1;
                
            }
            else if(target>letters[mid])
            {   

                start=mid+1;
            }
            else{
                if(letters[mid]-target<=closestDiff)
                {
                    closestDiff=letters[mid]-target;
                    closestChar=letters[mid];
                }
                end=mid-1;
            }
        }
        return closestChar;
    }

    char nextGreatestLetter(vector<char>& letters, char target) {
        
        char res=binSearch(letters,target);

        return res;
    }
};

int main()
{
    
    return 0;
}