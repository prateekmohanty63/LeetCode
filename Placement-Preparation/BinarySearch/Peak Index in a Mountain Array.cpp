#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int solve(vector<int>&arr)
    {
        int start=0;
        int end=arr.size()-1;
        int ind=-1;
        int n=arr.size();

        while(start<=end)
        {
            int mid=start+(end-start)/2;

            if(mid-1>=0 && mid+1<n && arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
            {
                return mid;
            }
            else if(mid-1>=0 && arr[mid]<arr[mid-1])
            end=mid-1;

            else if(mid+1<n && arr[mid]<arr[mid+1])
            start=mid+1;

            else break;
        }
        return -1;
    }
    int peakIndexInMountainArray(vector<int>& arr) {
        
        return solve(arr);
    }
};

int main()
{
    
    return 0;
}