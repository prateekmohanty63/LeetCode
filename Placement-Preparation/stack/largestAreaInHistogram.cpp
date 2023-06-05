#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int maxArea=INT_MIN;
        int n=heights.size();

        for(int i=n-1;i>=0;i--)
        {
            int minHeight=heights[i];
            maxArea=max(maxArea,minHeight);
            for(int j=i-1;j>=0;j--)
            {
                int currHeight=heights[j];
                minHeight=min(minHeight,currHeight);
                maxArea=max(maxArea,minHeight*(i-j+1));
            }
        }
        return maxArea;
    }
};

int main()
{
    
    return 0;
}