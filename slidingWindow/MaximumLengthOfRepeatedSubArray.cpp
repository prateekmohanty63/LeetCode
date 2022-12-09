#include<iostream>
#include<vector>
using namespace std;

// TLE
// 44/53
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        int n=nums1.size();
        int m=nums2.size();

        int maxLen=INT_MIN;

        for(int i=0;i<n;i++)
        {
            int a=nums1[i];

            for(int j=0;j<m;j++)
            {
                if(a==nums2[j])
                {
                    int ptr1=i;
                    int ptr2=j;

                    while(ptr1<n && ptr2<m && nums1[ptr1]==nums2[ptr2])
                    {
                        ptr1++;
                        ptr2++;
                    }

                    maxLen=max(maxLen,ptr1-i);

                }
            }
        }
        if(maxLen==INT_MIN)return 0;
        return maxLen;
    }
};

int main()
{
    
    return 0;
}