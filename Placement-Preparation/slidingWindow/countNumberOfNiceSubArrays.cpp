#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int res=0;

        int start=0;
        int end=0;
        int countOdd=0;

        while(end<n)
        {
           if(nums[end]%2!=0)countOdd++;

           if(countOdd==k)
           { 
               int endTemp=end+1;
               int count=0;

               while(endTemp<n && nums[endTemp]%2==0){
                   count++;
                   endTemp++;
             }  
              int count1=0;
              
              while(start<end && nums[start]%2==0){
                  count1++;
                  start++;
              }
              res+=(count+1)*(count1+1);
              countOdd--;
              start++;
              
           }
           end++;
        }

        return res;
    }
};

int main()
{
    
    return 0;
}