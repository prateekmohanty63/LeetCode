#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;


// T(N)=O(N^2)
// S(N)=O(N)

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        
        unordered_map<int,bool>ind;

        int n=arr.size();
        int maxCount=INT_MIN;

        for(int i=0;i<n-1;i++){

            if(ind.find(i)!=ind.end())continue; 

            ind[i]=true;
            int prevVal=arr[i];
            int count=0;

            for(int j=i+1;j<n;j++){
                
                if(arr[j]-prevVal==difference){
                    count++;
                    ind[j]=true;
                    prevVal=arr[j];
                }
            }
            maxCount=max(maxCount,count+1);

        }
        return maxCount;
    }
};

int main()
{
    
    return 0;
}