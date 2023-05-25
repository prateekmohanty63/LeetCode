#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>prefix(n,1);

        // longest increasing subsequence at any position is atleast 1

        for(int i=1;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(nums[j]<nums[i])
                {
                    prefix[i]=max(prefix[i],prefix[j]+1);
                }
            }
        }

        int minim=INT_MIN;

        for(auto it:prefix)
        minim=max(minim,it);
       
       return minim;
        
    }
};

int main()
{
    
    return 0;
}