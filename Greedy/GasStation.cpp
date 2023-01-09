#include<iostream>
#include<vector>
using namespace std;


// Corrrect solution 
// but TLE

class Solution {
public:


   
    int circularIndex(vector<int>&gas,vector<int>&cost,int i,int target,int currGas)
    {
        // base case
        int n=gas.size();

        if((i+1)%n==target && currGas>=cost[i%n])return target;

        if(currGas<=cost[i%n])return -1;

        
        int gasLeft=currGas-cost[i%n];

        return circularIndex(gas,cost,(i+1)%n,target,gasLeft+gas[(i+1)%n]);
        
      


    }
 
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int res=-1;

        int totalCost=0;
        int totalGas=0;

        // for(int i=0;i<n;i++)
        // {
        //     totalCost+=cost[i];
        //     totalGas+=gas[i];
        // }
        
        // if(totalCost<totalGas)return -1;

        //cout<<cirularIndex(gas,cost,3,4,4);
     
        for(int k=0;k<n;k++)
        {
            int target=k;
            int currGas=gas[k];
            int start=k;

            res=circularIndex(gas,cost,k,k,currGas);

            if(res!=-1)return res;
        }
        return res;
    }
};
int main()
{
    
    return 0;
}