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

