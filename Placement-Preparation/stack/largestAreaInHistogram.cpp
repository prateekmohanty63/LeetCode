#include<iostream>
#include<vector>
#include<stack>
#include<climits>
using namespace std;


// Optimized 
// T(N)=O()
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n=heights.size();
        int maxArea=INT_MIN;

        vector<int>left;
        vector<int>right(n,0);

        // checking the smallest from left 
        left.push_back(1);

        // stack 
        stack<int>stk;
        stk.push(0);

        for(int i=1;i<n;i++)               // <- O(N)
        {
            if(heights[stk.top()]<heights[i])
            {
                left.push_back(i-stk.top());
            }
            else{
                while(!stk.empty() && heights[stk.top()]>=heights[i])stk.pop();   // O(1)

                if(stk.empty())
                {
                    left.push_back(i+1);
                }
                else{
                    left.push_back(i-stk.top());
                }
            }
            stk.push(i);
        }

        stack<int>stk1;
        int k=n-1;
        right[k--]=1;

        stk1.push(n-1);

        for(int i=n-2;i>=0;i--)
        {
            if(heights[stk1.top()]<heights[i])
            {
                 right[k--]=stk1.top()-i;
            }
            else{
                while(!stk1.empty() && heights[stk1.top()]>=heights[i])
                stk1.pop();

                if(stk1.empty())
                {
                    //cout<<i<<" ";
                    right[k--]=n-i;
                }
                else{
                    right[k--]=stk1.top()-i;
                }
            }
            stk1.push(i);
        }
        // cout<<endl;
        // for(int i=0;i<n;i++)cout<<left[i]<<" ";
        // cout<<endl;
        // for(int i=0;i<n;i++)cout<<right[i]<<" ";

        for(int i=0;i<n;i++)
        {
            maxArea=max(maxArea,heights[i]*left[i]+heights[i]*(right[i]-1));
        }

        return maxArea;
    }
};

// Brute force

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