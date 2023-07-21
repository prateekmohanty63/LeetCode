#include<iostream>
#include<vector>
#include<stack>

using namespace std;


// T(N)=O(N)
// S(N)=O(N)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n=heights.size();

        int max_area=0;

        vector<int>l;
        vector<int>r;

        stack<int>left;
        stack<int>right;

        for(int i=0;i<n;i++)
        {
            int leftSmallest=-1;
            

            int currEle=heights[i];

           
            while(!left.empty() && heights[left.top()]>=currEle)
            left.pop();

            if(!left.empty())
            {
                leftSmallest=left.top();
            }
            l.push_back(leftSmallest);
            left.push(i);
            
        }

        for(int i=n-1;i>=0;i--)
        {
            int rightSmallest=-1;
            int currEle=heights[i];

            while(!right.empty() && heights[right.top()]>=currEle)
            right.pop();

            if(!right.empty())
            {
                rightSmallest=right.top();
            }
            r.push_back(rightSmallest);
            right.push(i);
        }
        
         n=l.size();

        for(int i=0;i<n;i++)
        {
            int leftSmallest=l[i];
            int rightSmallest=r[n-i-1];

            //cout<<leftSmallest<<" "<<rightSmallest<<endl; 

            int width;

             if(leftSmallest==-1 && rightSmallest==-1)
            {
                  width=n;
            }
            else if(leftSmallest==-1)
            {
                  width=(i)+(1)+(rightSmallest-i-1);
            }
            else if(rightSmallest==-1)
            {
                 width=(i-leftSmallest-1)+(1)+(n-i-1);
            }
            else{
                 width=(i-leftSmallest-1)+(1)+(rightSmallest-i-1);
            }
            max_area=max(max_area,width*heights[i]);
        }

        return max_area;
    }
};

int main()
{
    
    return 0;
}