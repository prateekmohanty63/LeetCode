#include<iostream>
#include<vector>
#include<climits>
#include<cmath>

using namespace std;


class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int n=piles.size();
        int start=1;
        int end=1000000000;
        int res=INT_MAX;

        while(start<=end)
        {
            int mid=start+(end-start)/2;

            double timeReq=0;

            for(int i=0;i<n;i++)
            {
                 timeReq+=ceil(piles[i]/(double)mid);
            }

            if(timeReq<=h)
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