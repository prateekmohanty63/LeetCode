#include<iostream>

using namespace std;

bool isBadVersion(int n)
{
    // this function is predefined 
    // checkes if version is bad or not
}

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        int start=1;
        int end=n;
        int res;

        while(start<=end)
        {
             int mid=start+(end-start)/2;
             
             if(isBadVersion(mid))
             {
                 res=mid;
                 end=mid-1;
             }
             else{
                 start=mid+1;
             }
        }
        return res;
    }
};

int main()
{
    
    return 0;
}