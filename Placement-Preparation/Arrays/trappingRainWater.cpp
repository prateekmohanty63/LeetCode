#include<iostream>
#include<vector>
#include<climits>
using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        
        int n=height.size();
        vector<int>maxLeft(n,0);
        vector<int>maxRight(n,0);
        
        maxLeft[0]=height[0];
        int currMax=height[0];

        int res=0;

        for(int i=1;i<n;i++)
        {
            currMax=max(currMax,height[i]);
            maxLeft[i]=currMax;
           
        }

        maxRight[n-1]=height[n-1];
        currMax=height[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
            currMax=max(currMax,height[i]);
            maxRight[i]=currMax;
        }

        for(int i=0;i<n;i++)
        {
            if(height[i]<=min(maxRight[i],maxLeft[i]));
            res+=min(maxRight[i],maxLeft[i])-height[i];
        }
      return res;
    }
};

int main()
{
    
    return 0;
}