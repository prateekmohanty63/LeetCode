#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>

using namespace std;

class Solution {
public:
    int minimumSeconds(vector<int>& nums) {

       int n=nums.size();
       unordered_map<int,vector<int>>valToInd;

       for(int i=0;i<n;i++)
       {
           valToInd[nums[i]].push_back(i);
       }   

       int ans=INT_MAX;

       // we will try to make all elements in the array equal to the distinct elements
       // present in the array and check the time taken in each case
       // and find the min time from all those and return 

       for(auto it:valToInd)
       {
           int eleToChange=it.first;
           vector<int>vec=it.second;
           int maxi=0;
           int m=vec.size();

           if(vec.size()==1)maxi=n/2;
            
            else{
           for(int i=0;i<m;i++)
           {
               maxi=max(maxi,(abs(vec[(i+1)%m]-vec[i]+n)%n)/2);
           }
         }
         ans=min(ans,maxi);
       }
       return ans;
    }
};

int main()
{
    
    return 0;
}