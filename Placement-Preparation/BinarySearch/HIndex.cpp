#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
  
    int hIndex(vector<int>& citations) {
        
        sort(citations.begin(),citations.end());
        int maxRes=-1;

        int start=0;
        int end=citations.size()-1;
        int n=citations.size();

        while(start<=end)
        {
            int mid=start+(end-start)/2;

            if(citations[mid]>=n-mid)
            {
                maxRes=max(maxRes,n-mid);
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        
        if(maxRes==-1)return 0;
        return maxRes;
    }
};

int main()
{
    
    return 0;
}