#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;


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