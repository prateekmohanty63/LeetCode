#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

// T(N)=O(nlogn)    // n=maxim element in the array (max=10^6)
// S(N)=O(1)

class Solution {
public:
    long long cst(int ele,vector<pair<int,int>>&nums)
    {
        int n=nums.size();
        long long cost=0;

        for(int i=0;i<n;i++){
          cost+=(long long)(abs(ele-nums[i].first))*(long long)(nums[i].second);
        }
        return cost;
    }

    long long solve(vector<pair<int,int>>&nums)
    {
         sort(nums.begin(),nums.end());
         long long costMin=LLONG_MAX;

         int leftEle=nums[0].first;
         int rightEle=nums[nums.size()-1].first;

         while(leftEle<=rightEle){
             
             int mid=leftEle+(rightEle-leftEle)/2;

             long long currCost=(long long)cst(mid,nums);
             costMin=min(costMin,currCost);
             
              long long leftPartCost=(long long)cst(mid-1,nums);
              long long rightPartCost=(long long)cst(mid+1,nums);

              if(leftPartCost<=rightPartCost)rightEle=mid-1;
              else leftEle=mid+1;
         }
         return costMin;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        
        int n=nums.size();

        vector<pair<int,int>>vec;

        for(int i=0;i<n;i++)
        {
            pair<int,int>pr;
            pr.first=nums[i];
            pr.second=cost[i];
            vec.push_back(pr);
        }

        long long res=(long long)solve(vec);

        return res;
    }
};


// T(N)=O(n^2)
// S(N)=O(n)
class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        
        int n=nums.size();
        vector<pair<int,int>>vec;

        for(int i=0;i<n;i++)
        {
            pair<int,int>pr;
            pr.first=nums[i];
            pr.second=cost[i];
            vec.push_back(pr);
        }
        // sorting the vec
        sort(vec.begin(),vec.end());

        long long minCost=LLONG_MAX;

        for(int i=0;i<n;i++)
        {
            int ele=vec[i].first;
            long long cst=0;

            for(int j=0;j<n;j++)
            {
                int ele1=vec[j].first;
                cst+=(long long)((long long)abs(ele-ele1)*((long long)vec[j].second));
            }
            minCost=min(minCost,cst);
        }
        return minCost;
    }
};

int main()
{
    
    return 0;
}