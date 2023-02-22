#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:

bool canShip(vector<int>&weight,int cap,int days)
{
     int k=0;
     int daysReq=1;
     int temp=cap;

     while(k<weight.size())
     {
         if(weight[k]<=temp)
         {
             temp-=weight[k];
               k++;
         }
         else{
             daysReq++;
             temp=cap;
         }
       
     }

     if(daysReq>days)return false;

     return true;
}
   
 int shipWithinDays(vector<int>& weights, int days) {
        
        // we have to keep the ship capacity at minimum
        // hence we will use all days to transport all the packets
        
         int minCapacityNeeded=INT_MIN;
         int n=weights.size();
         int maxCapacityNeeded=0;

         for(int i=0;i<n;i++)
         {
             minCapacityNeeded=max(minCapacityNeeded,weights[i]);
             maxCapacityNeeded+=weights[i];
         }
        
        // we need atleast a capacity equal to max of the package weight
        // but to send wihin days more capacity might be required

        int start=minCapacityNeeded;
        int end=maxCapacityNeeded;
        int res=INT_MAX;

        while(start<=end)
        {
            int cap=start+(end-start)/2;
             
             if(canShip(weights,cap,days))
             {
                 res=min(res,cap);
                 end=cap-1;
             }
             else{
                start=cap+1;
             }
            

        }      
         return res;
    }
};

int main()
{
    
    return 0;
}