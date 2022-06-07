#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Runtime: 5 ms, faster than 34.50% of C++ online submissions for Merge Sorted Array.
//Memory Usage: 9.1 MB, less than 72.57% of C++ online submissions for Merge Sorted Array.

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i=m-1;
        int j=n-1;
        int k=n+m-1;
        
        while(j>=0)
        {
            if(i>=0 && nums1[i]>nums2[j])
            {
                nums1[k--]=nums1[i--];
            }
            else{
                nums1[k--]=nums2[j--];
            }
        }
    }
};

// Runtime: 7 ms, faster than 24.43% of C++ online submissions for Merge Sorted Array.
// Memory Usage: 9.2 MB, less than 30.68% of C++ online submissions for Merge Sorted Array.


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        vector<int>auxiliary;
      
        
        int i = 0, j = 0, k = 0;
 
    // Traverse both array
    while (i<m && j<n)
    {
        if (nums1[i] < nums2[j])
            auxiliary.push_back(nums1[i++]);
        else
            auxiliary.push_back(nums2[j++]);
    }
        
        while(i!=m)
        {
            auxiliary.push_back(nums1[i++]);
        
        }
         while(j!=n)
        {
            auxiliary.push_back(nums2[j++]);
           
        }
        
        
        for(int i=0;i<auxiliary.size();i++)
           nums1[i]=auxiliary[i];
    }
};

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