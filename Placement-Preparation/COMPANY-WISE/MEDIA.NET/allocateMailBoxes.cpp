#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;


class Solution {
public:
    int solve(vector<int>&houses,int index,int k)
    {
        // base case
        int n=houses.size();
        if(index>=n)return 0;
        if(k==0)return 0;

        if(k==1)
        {
            // we have to cover all the remining houses with 
            // the mailbox remaining 
            int median=((n-1)-index)/2;
            int mailBoxPos=houses[index+median];
            int totalCost=0;
            for(int j=index;j<n;j++)
            {
                totalCost+=abs(houses[j]-mailBoxPos);
            }
            return totalCost;
        }

        int ans=INT_MAX;

        for(int i=index;i<n;i++)
        {
             int median=(i-index)/2;
             int mailBoxPos=houses[index+median];
             
             int cost=0;
             for(int k=index;k<=i;k++)cost+=abs(houses[k]-mailBoxPos);
    
             ans=min(ans,cost+solve(houses,i+1,k-1));
        }
        return ans;
    }
    int minDistance(vector<int>& houses, int k) {
        
        sort(houses.begin(),houses.end());

        int res=solve(houses,0,k);

        return res;


    }
};

int main()
{
    
    return 0;
}