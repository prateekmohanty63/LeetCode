#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:


   
    int cirularIndex(vector<int>&gas,vector<int>&cost,int i,int target,int currGas)
    {
        // base case
        int n=gas.size();

         if(currGas>=cost[i%n] && (i+1)%n==target)return target;

         if(currGas<=cost[i%n])return -1;

        if(currGas<=0)return -1;

        int gasLeft=currGas-cost[i]+gas[(i+1)%n];

       return cirularIndex(gas,cost,(i+1)%n,target,gasLeft);


    }
 
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        
        //cout<<cirularIndex(gas,cost,3,4,4);
     
        for(int k=0;k<n;k++)
        {
            int target=k;
            int currGas=gas[k];
            int start=(k+1)%n;

            int res=cirularIndex(gas,cost,start,target,currGas);

            if(res!=-1)return res;
        }
        return -1;
    }
};

int main()
{
    
    return 0;
}