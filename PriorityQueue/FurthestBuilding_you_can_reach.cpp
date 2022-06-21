#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Runtime: 191 ms, faster than 26.71% of C++ online submissions for Furthest Building You Can Reach.
// Memory Usage: 54 MB, less than 14.85% of C++ online submissions for Furthest Building You Can Reach.

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        int n=heights.size();
        
        priority_queue<int>maxBrick;
        int i=0;
        
        for(i=0;i<n-1;i++)
        {
            int a=heights[i+1]-heights[i];
            
            if(a<=0)
            {
                continue;
            }
            
            bricks-=a;
            maxBrick.push(a);
            
            if(bricks<0)
            {
                bricks+=maxBrick.top();
                maxBrick.pop();
                ladders--;
            }
            
            if(ladders<0)break;
            
        }
        return i;
    }
};

int main()
{
    
    return 0;
}