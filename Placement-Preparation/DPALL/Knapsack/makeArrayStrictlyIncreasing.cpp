#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
#include<algorithm>
using namespace std;

class Solution {
public:

   long long solve(vector<int>&arr1,vector<int>&arr2,int prevEle,int index,unordered_map<string,long long>&dp)
   {
       // base case
       int n=arr1.size();

       if(index>=n)return 0;

       string res=to_string(index)+"*"+to_string(prevEle);

       if(dp.find(res)!=dp.end())return dp[res];

     
       long long ans=INT_MAX;

       if(arr1[index]>prevEle){
           // here we have two options either to move to next index
           // or change the current element also
            int ind=upper_bound(arr2.begin(),arr2.end(),prevEle)-arr2.begin();
            if(ind>=0 && ind<arr2.size()){
            int ele=arr2[ind];
           ans=min(ans,min(solve(arr1,arr2,arr1[index],index+1,dp),1+solve(arr1,arr2,ele,index+1,dp)));
            }
            else{
                ans=min(ans,solve(arr1,arr2,arr1[index],index+1,dp));
            }
       }
       else{
           // we have to change , no option here
            int ind=upper_bound(arr2.begin(),arr2.end(),prevEle)-arr2.begin();
            if(ind>=0 && ind<arr2.size()){
            int ele=arr2[ind];
            ans=min(ans,1+solve(arr1,arr2,ele,index+1,dp));
            }
            else return INT_MAX;
       }
       return dp[res]=ans;
   }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        
        // sorting the 2nd array
        sort(arr2.begin(),arr2.end());

        int n=arr1.size();

        int maxim=INT_MIN;

        for(auto it:arr2)maxim=max(maxim,it);

        unordered_map<string,long long>dp;

        int res=solve(arr1,arr2,-1,0,dp);

        if(res==INT_MAX)return -1;

        return res;


    }
};

int main()
{
    
    return 0;
}