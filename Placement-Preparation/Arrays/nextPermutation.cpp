#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        vector<int>vec1=nums;
       vector<int>vec;
       int n=nums.size();

       for(int i=n-2;i>=0;i--)
       {
          
           int closestInd=-1;
           int maxDiff=INT_MAX;
           
           for(int j=i+1;j<n;j++)
           {
                if(nums[j]>nums[i])
                {
                    if(nums[j]-nums[i]<maxDiff)
                    {
                        maxDiff=nums[j]-nums[i];
                        closestInd=j;
                    }
                }
               
           }
           if(closestInd!=-1)
           {
               vector<int>suffix;
                swap(nums[i],nums[closestInd]);
               
               for(int j=i+1;j<n;j++)
               {
                   suffix.push_back(nums[j]);
               }
             
               sort(suffix.begin(),suffix.end());
               for(auto it:suffix)cout<<it<<" ";
              int k=0;
              for(int j=i+1;j<n;j++){
                  if(k<suffix.size())nums[j]=suffix[k++];
              }

              break;
           }
       }
       if(vec1==nums){
           sort(vec1.begin(),vec1.end());
           nums=vec1;
       }
    }
};

int main()
{
    
    return 0;
}