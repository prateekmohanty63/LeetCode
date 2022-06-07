#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Runtime: 4 ms, faster than 49.07% of C++ online submissions for Merge Sorted Array.
// Memory Usage: 9.1 MB, less than 30.68% of C++ online submissions for Merge Sorted Array.
// runtime is O(nlog)


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int pointer1=0;
        int pointer2=0;
        cout<<m;
        int r=m;
        
        for(int i=0;i<n;i++)
        {
            nums1[r++]=nums2[i];
        }
        
        sort(nums1.begin(),nums1.end());
    }
};

int main()
{
    
    return 0;
}