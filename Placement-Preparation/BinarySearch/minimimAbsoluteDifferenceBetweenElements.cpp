#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<climits>
using namespace std;


class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        
        int n=nums.size();
        int ans=INT_MAX;

        set<int>set1;

        for(int i=n-x-1;i>=0;i--)
        {
            // insert the element xth position away from current element
            set1.insert(nums[i+x]);

            // now we find the lower bound of the current element
            auto it=set1.lower_bound(nums[i]);

            if(it==set1.end())
            {
                // there is no lower bound of the current element
                // then all the elements are smaller than the current element
                // hence the closest element will be the last element of the sorted set

                it--;
                ans=min(ans,abs(nums[i]-*it));
            }
            else{
                // it has a lower bound we check the lower bound
                // and the element just smaller than lower bound
               
               if(it==set1.begin())
               {
                   ans=min(ans,abs(nums[i]-*it));
               }
               else{
                ans=min(ans,abs(nums[i]-*it));
                it--;
                ans=min(ans,abs(nums[i]-*it));
               }

            }
        }
        return ans;
    }
};


class Solution {
public:

    bool isSolution(vector<int>&nums,int mid,int x)
    {
        int n=nums.size();

        // ordered_set
        set<int>set1;

        for(int i=n-x-1;i>=0;i--)
        {
            // put element after x spaces into set
            set1.insert(nums[i+x]);

            auto it=set1.lower_bound(nums[i]);

            // if it is pointing to start of the set
            // then this is the least distance possible

            if(it==set1.begin()){
            if(abs(*it-nums[i])<=mid)return true;
            }
            else{
                // [5,3,2,10,15]
                // for i=1 , set={2,10,15}
                // lower_bound(3)=10
                // but there is also 2 available
                // hence this is the boundary 
                // we will check the previous value as well

                if(abs(*it-nums[i])<=mid)return true;

                it--;
                if(abs(*it-nums[i])<=mid)return true;
            }

        }
       return false;
        
    }
    int minAbsoluteDifference(vector<int>& nums, int x) {
        
        int minElement=*min_element(nums.begin(),nums.end());
        int maxElement=*max_element(nums.begin(),nums.end());

        int left=0;
        int right=maxElement-minElement;

        int res=-1;

        while(left<=right)
        {
            int mid=left+(right-left)/2;

            if(isSolution(nums,mid,x))
            {
                res=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return res;
    }
};

int main()
{
    
    return 0;
}