#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;



class Solution {
public:
   int binSearch(vector<int>&nums,int target,int start,int end)
   {
       // base case

       if(start<=end)
       {
           int mid=start+(end-start)/2;

           if(nums[mid]==target)return mid;

           if(target>nums[mid])return binSearch(nums,target,mid+1,end);

           else return binSearch(nums,target,start,mid-1);
       }
       return -1;

   }
    vector<vector<int>> threeSum(vector<int>& nums) {

        int flag=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)flag=1;
        }
        if(flag==0)
        {
            vector<int>vec;
            vec.push_back(0);
            vec.push_back(0);
            vec.push_back(0);
            return {vec};
        }
        
        set<vector<int>>set1;
        vector<vector<int>>res;
        int n=nums.size();

        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int target=0-(nums[i]+nums[j]);

                int ind=binSearch(nums,target,j+1,n-1);

                if(ind!=-1)
                {
                    vector<int>vec;
                    vec.push_back(nums[i]);
                    vec.push_back(nums[j]);
                    vec.push_back(nums[ind]);
                    sort(vec.begin(),vec.end());
                    set1.insert(vec);
                }
            }
        }

         for(auto it:set1)
         {
             res.push_back(it);
         }

        return res;
    }
};

int main()
{
    
    return 0;
}