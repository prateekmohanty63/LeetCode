#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
  
    int minimizeMax(vector<int>& nums, int p) {
        
       
        int n=nums.size();

        sort(nums.begin(),nums.end());
        int start=0;
        int end=nums[n-1]-nums[0];

        if(p==0)return 0;

        int ans;

        while(start<=end)
        {
            int mid=start+(end-start)/2;
            // we check if there are enough pairs with difference
            // less than or equal to this
            int k=0;
            int countOfPairs=0;
            while(k<n)
            {
                if(k+1<n && nums[k+1]-nums[k]<=mid)
                {
                    countOfPairs++;
                    k+=2;
                }
                else k++;
            }
            // if there are enough pairs , this can possibily be an answer
            if(countOfPairs>=p)
            {
                ans=mid;
                // we check if the difference can be lesser
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};

int main()
{
    
    return 0;
}