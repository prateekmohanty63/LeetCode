#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<math.h>
using namespace std;


   int numSubseq(vector<int>& nums, int target) {
        
        int n=nums.size();
        int mod = 1000000007;
        int res=0;

        //if(n==1)return 1;

        sort(nums.begin(),nums.end());

        int start=0;
        int end=n-1;

         
         for(int i=0;i<n;i++)
         {
             int sum=nums[i];
             if(end<i)break;

             while(end>=0 && end>=i && sum+nums[end]>target)
             {
                  end--;
             }
             if(end>=i){
             int size=end-i;
             cout<<nums[start]<<" "<<nums[end]<<endl; 
             res+=(pow(2,size))%mod;
             }

         }

       return res%mod;
    }

int main()
{

    vector<int>nums={14,4,6,6,20,8,5,6,8,12,6,10,14,9,17,16,9,7,14,11,14,15,13,11,10,18,13,17,17,14,17,7,9,5,10,13,8,5,18,20,7,5,5,15,19,14};
    int target=22;

    cout<<numSubseq(nums,target);
    
    return 0;
}