#include<iostream>
#include<vector>
using namespace std;


// brute force 
//  T(N)=O(N^3)

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        int n=nums.size();
       
       if(n<3)return false;

       for(int i=2;i<n;i++)
       {
           int mid=nums[i];
           for(int j=i-1;j>=1;j--)
           {
               int end=nums[j];

               for(int k=j-1;k>=0;k--)
               {
                   int start=nums[k];

                   if(start<mid && end>mid)return true;
               }
           }
       }
        return false;
    }
};

int main()
{
    
    return 0;
}