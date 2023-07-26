#include<iostream>
#include<climits>
#include<vector>
#include<cmath>

// T(N)=O(n*log(100000000))

using namespace std;

class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        
        int totalDistance=0;
        int n=dist.size();

        

        int start=1;
        int end=1000000000;
        int res=INT_MAX;
       

        while(start<=end)
        {
            int mid=start+(end-start)/2;
           // cout<<mid<<" ";

            double timeReq=0;

            for(int i=0;i<n-1;i++)timeReq+=ceil(dist[i]/(double)mid);
            timeReq+=(dist[n-1]/(double)mid);
           

            if(timeReq<=hour)
            {
                res=min(res,mid);
                end=mid-1;
            }
            else if(timeReq>hour)
            {
                start=mid+1;
            }
        }
        if(res==INT_MAX)return -1;

        return res;
    }
};

int main()
{
    
    return 0;
}