#include<iostream>
#include<vector>
#include<climits>

using namespace std;


// NOTE: Here that the lower height among the two pointers is the limiting factor 
// hence always we will  move the pointer which is smaller , in bid to increase the height 

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int start=0;
        int end=height.size()-1;

        int maximArea=INT_MIN;

        while(start<end)
        {
            int ht=min(height[start],height[end]);
            int len=(end-start);

            maximArea=max(maximArea,ht*len);
            
            if(height[start]<height[end])start++;

            else end--;
             
        }
        return maximArea;
    }
};

int main()
{
    
    return 0;
}