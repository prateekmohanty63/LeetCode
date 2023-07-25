#include<iostream>
#include<vector>
#include<climits>
using namespace std;


class Solution {
public:
   
   int maxSumWindow(vector<int>&nums,int winLen)
   {
       int start=0;
       int end=winLen-1;
       int n=nums.size();

       int strInd;

       int sum=0;

       for(int i=start;i<=end;i++)
       {
           sum+=nums[i];
       }

        int maxSum=sum;
    

       while(end+1<n)
       {
           sum-=nums[start];
           sum+=nums[end+1];
        
          if(sum>maxSum)
          {
              maxSum=sum;

          }
         

           start++;
           end++;
       }

     return maxSum;
   }

    int maxSumPossible(vector<int>&nums,int firstLen,int secondLen)
   {
        int sum=0;

        int start=0;
        int end=firstLen-1;
        int maxSum=INT_MIN;
        int n=nums.size();

        for(int i=start;i<=end;i++)
        sum+=nums[i];

        vector<int>vec;

        for(int i=end+1;i<n;i++)
        {
            vec.push_back(nums[i]);
        }
        int sum1;
        sum1=sum+maxSumWindow(vec,secondLen);

        maxSum=max(maxSum,sum1);

        while(end+1<n)
        {
             sum-=nums[start];
             sum+=nums[end+1];

             start++;
             end++;

             vector<int>num2;

             for(int i=0;i<n;i++)
             {
                 if(i>=start && i<=end)continue;

                  num2.push_back(nums[i]);
             }
           
           int sum2=sum+maxSumWindow(num2,secondLen);

           maxSum=max(maxSum,sum2);

        }

     return maxSum;

   }

    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        
       int res=maxSumPossible(nums,firstLen,secondLen);

       return res;

    
    }
};

int main()
{
    
    return 0;
}