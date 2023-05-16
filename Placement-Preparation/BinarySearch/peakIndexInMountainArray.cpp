#include<iostream>
#include<vector>
using namespace std;

// T(N)=O(nlogn)
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int start=0;
        int end=arr.size()-1;
        int n=arr.size();

        while(start<=end)
        {
            int mid=start+(end-start)/2;

            if(mid+1<n && mid-1>=0 && arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])return mid;

            else if(mid-1>=0 && arr[mid-1]>arr[mid])
            {
                 end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return -1;
    }
};

// Time complexity: O(n)

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int n=arr.size();

        for(int i=1;i<n-1;i++)
        {
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1])return i;
        }
        return -1;
    }
};

int main()
{
    
    return 0;
}