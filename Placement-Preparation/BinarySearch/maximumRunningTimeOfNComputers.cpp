#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
   bool isPossible(vector<int>&batteries,long long time,int computers)
   {
       long long totalBatteryTimeNeeded=time*computers;

       for(long long bTime:batteries)
       totalBatteryTimeNeeded-=min(time,bTime);

       return (totalBatteryTimeNeeded<=0);
   }
    long long maxRunTime(int n, vector<int>& batteries) {
        
        long long start=0;
        long long end=0;
        long long ans=0;

        for(auto it:batteries)end+=it;

        while(start<=end)
        {
            long long mid=start+(end-start)/2;

            if(isPossible(batteries,mid,n))
            {
                ans=mid;
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return ans;
    }
};

int main()
{
    
    return 0;
}