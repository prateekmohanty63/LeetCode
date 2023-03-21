#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:   

    long long zeroFilledSubarray(vector<int>& nums) {

      long long res=0;
      int n=nums.size();

      vector<int>continousArr;

      for(int i=0;i<n;i++)
      {
          if(nums[i]==0)
          {
              int start=i;
              int end=i+1;
              

              while(end<n && nums[end]==0)
              {
                   end++;
              }

              long long count=(end-start);
              res+=(count)*(count+1)/2;
              i=end;
              continousArr.push_back(count);
          }
      }

    //   for(auto it:continousArr)
    //   {
    //       int countOne=it;

    //       for(int i=1;i<=countOne;i++)
    //       {
    //           int c=nCr(countOne,i);
    //           cout<<c<<" ";
    //           res+=c;
    //       }

    //   }

      return res;

    }
};

int main()
{
    
    return 0;
}