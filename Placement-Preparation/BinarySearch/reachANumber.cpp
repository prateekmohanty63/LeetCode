#include<iostream>
#include<climits>
using namespace std;

// brute force 
class Solution {
public:
   
   int minSteps(int source,int target,int steps)
   {
       // base case
       if(source==target)return steps;

       if(abs(source)>target)return INT_MAX;

       return min(minSteps(source+steps+1,target,steps+1),minSteps(source-steps-1,target,steps+1));
;
   }

    int reachNumber(int target) {
        
        return minSteps(0,abs(target),0);
    }
};

int main()
{
    
    return 0;
}