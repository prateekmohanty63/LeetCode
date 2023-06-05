#include<iostream>
#include<vector>
#include<stack>
#include<climits>
using namespace std;

class Solution {
public:
    
    int maxAreaReactangle(vector<int>&heights)
    {
        int n=heights.size();
        vector<int>left;
        vector<int>right(n,0);

        int maxArea=INT_MIN;

        // stack 
        stack<int>stk;
        left.push_back(1);
        stk.push(0);
       
       for(int i=1;i<n;i++)
       {
           if(heights[stk.top()]<heights[i])
           {
               left.push_back(i-stk.top());
           }
           else{
               while(!stk.empty() && heights[stk.top()]>=heights[i])stk.pop();

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

       int k=n-1;
       right[k--]=1;

       stack<int>stk1;

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

               if(stk1.empty())right[k--]=n-i;

               else right[k--]=stk1.top()-i;
           }
           stk1.push(i);
       }
       for(int i=0;i<n;i++)
       {
           maxArea=max(maxArea,heights[i]*left[i]+heights[i]*(right[i]-1));
       }
       return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        int maxArea=INT_MIN;

        for(int i=0;i<n;i++)
        {
            vector<int>heights;
            for(int j=0;j<m;j++)
            {
                int count=0;
                int k=i;
                while(k>=0)
                {
                  if(matrix[k][j]=='0')break;

                   count++;
                    k--;
                }
                heights.push_back(count);

            }
             for(auto it:heights)cout<<it<<" ";
                cout<<endl;
            maxArea=max(maxArea,maxAreaReactangle(heights));
        }

        return maxArea;
    }
};

int main()
{
    
    return 0;
}