#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;


class Solution {
public:
    int binSearch(vector<int>&nums,int target,int s)
    {
        int n=nums.size();
        int start=s;
        int end=n-1;

        while(start<=end)
        {
            int mid=start+(end-start)/2;
            
            if(nums[mid]==target)return mid;

            if(target<nums[mid])
            end=mid-1;

            else start=mid+1;
        }
        return -1;
    }
    int findPairs(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int start=0;
        int end=n-1;

        map<pair<int,int>,bool>mp;

        for(int i=0;i<n;i++)
        {
            int num1=nums[i];
            int target1=k+num1;
            int target2=-k+num1;

            int ind1=binSearch(nums,target1,i+1);
            int ind2=binSearch(nums,target2,i+1);

            if(ind1!=-1)
            mp[{num1,nums[ind1]}]=true;

            if(ind2!=-1)
            mp[{num1,nums[ind2]}]=true;

        }

        for(auto it:mp)
        cout<<it.first.first<<" "<<it.first.second<<endl;

          return mp.size();
    }
};

int main()
{
    
    return 0;
}