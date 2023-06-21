#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

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