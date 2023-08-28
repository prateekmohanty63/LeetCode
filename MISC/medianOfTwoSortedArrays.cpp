#include<iostream>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n=nums1.size();
        int m=nums2.size();
        
        int first=0,second=0;
        
        vector<int>res;
        
        while(first<n && second<m)
        {
            if(nums1[first]<nums2[second])
            {
                res.push_back(nums1[first]);
                first++;
            }
            else{
                res.push_back(nums2[second]);
                second++;
            }
        }
        
        while(first<n)
        {
            res.push_back(nums1[first]);
            first++;
        }
        
        while(second<m)
        {
            res.push_back(nums2[second]);
            second++;
        }
        
        
        if((n+m)%2!=0)
        {
            return res[(n+m)/2];
        }
        else{
            
            double a=(double)(res[(n+m)/2]+res[(n+m)/2 -1])/(double)2;
                        
            return a;
        }
        return -1;
    }
};

int main()
{
    
    return 0;
}