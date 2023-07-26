#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {

       int sum=0;

       for(auto it:weights)
       sum+=it;
       
       int start=1;
       int end=sum;
       int n=weights.size();
       int res=INT_MAX;
      
      int maxWeight=INT_MIN;
      for(auto it:weights)maxWeight=max(maxWeight,it);

       while(start<=end)
       {
           int mid=start+(end-start)/2;

           // check if possible to ship within d days
           int k=0;
           int daysReq=1;
           int weightShip=mid;

           if(mid<maxWeight)
           {
               start=mid+1;
           }
          else{
           while(k<n)
           {
               if(weights[k]<=weightShip)
               {
                   weightShip-=weights[k];
               }
               else {
                   daysReq++;
                   weightShip=(mid-weights[k]);
               }
               k++;
           }

           if(daysReq<=days)
           {
                res=mid;
                end=mid-1;
           }
           else{
               start=mid+1;
           }
          }

       }

     return res;
    }
};

int main()
{
    
    return 0;
}