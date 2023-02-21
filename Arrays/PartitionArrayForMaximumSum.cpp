#include<iostream>
#include<vector>
#include<climits>
using namespace std;


// solutiong giveing TLE (need to convert to dp)
class Solution {
public:
   
   int maxSumPossible(vector<int>&arr,int i,int k)
   {
       // base case

       if(i>=arr.size())return 0;

       int n=arr.size();

       int maxim=INT_MIN;

       int maxRes=INT_MIN;

        for(int j=i;j<min(n,i+k);j++)
        {
             maxim=max(maxim,arr[j]);

             int sum=(j-i+1)*maxim;

             maxRes=max(maxRes,sum+maxSumPossible(arr,j+1,k));
        }
        return maxRes;
   }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        int res=maxSumPossible(arr,0,k);

        return res;
    }
};

int main()
{
    
    return 0;
}