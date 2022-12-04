#include<iostream>
#include<vector>
#include<cmath>
using namespace std;


// Runtime
// 278 ms
// Beats
// 54.47%

// Memory
// 84.7 MB
// Beats
// 28.51%


class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
          
          int n=nums.size();
          vector<double>avg(n,0);
          int res;

          if(n==0)return 0;

          int flag=-1;
          for(int i=0;i<n;i++)
          {
              if(nums[i]!=0)flag=1;
          }

          if(flag==-1)return 0;

          double sum=0;

          for(int i=0;i<n;i++)
          {
              sum+=nums[i];

              avg[i]=sum;
          }

          int minDiff=INT_MAX;

          for(int i=0;i<n;i++)
          {
              float firstAvg=floor(avg[i]/(float)(i+1));
               
               float secondAvg;
               if(n-(i+1)>0)
              secondAvg=floor((avg[n-1]-avg[i])/(float)(n-(i+1)));

             else secondAvg=0;
             // cout<<firstAvg<<" "<<secondAvg<<endl;

              double diff=abs(firstAvg-secondAvg);

              if(diff<minDiff)
              {
                  minDiff=diff;
                  res=i;
              }
          }

          return res;
    }
};

int main()
{
    
    return 0;
}