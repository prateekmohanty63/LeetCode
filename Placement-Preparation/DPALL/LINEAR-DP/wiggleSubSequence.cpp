#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class Solution {
public:
   
   int maxSubSequence(vector<int>&nums,int i,int flag)
   {
       int n=nums.size();
       // flag is to check if the previous difference was negative or positive 

       // base case
       if(i>=n)return 0;

     // flag==1 (positive)
     // flag==0 (negative)

       int maxRes=INT_MIN;

       for(int j=i+1;j<n;j++)
       {
           if(flag==1)
           {
               // current difference is positive 
                int nextDiff=nums[j]-nums[i];
                
                if(nextDiff<0)
                {
                    maxRes=max(maxRes,1+maxSubSequence(nums,j,0));
                }
                else{
                    maxRes=max(maxRes,maxSubSequence(nums,i+1,flag));
                }

           }
           else
           {
               // current difference is negative 
               int nextDiff=nums[j]-nums[i];

               if(nextDiff>0)
               {
                   maxRes=max(maxRes,1+maxSubSequence(nums,j,1));
               }
               else{
                    maxRes=max(maxRes,maxSubSequence(nums,i+1,flag));
                }
           }
       }
       return maxRes;
   }
    int wiggleMaxLength(vector<int>& nums) {
        
        int n=nums.size();

        int res=maxSubSequence(nums,0,0);
        int res1=maxSubSequence(nums,0,1);

        cout<<res<<" "<<res1;

        return max(res,res1);
    }
};

int main()
{
    
    return 0;
}