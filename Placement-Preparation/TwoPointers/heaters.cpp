#include<iostream>
#include<vector>
#include<climits>
using namespace std;


// brute force 
// TLE

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        
        int n=houses.size();
        int maxRadius=INT_MIN;

         for(int i=0;i<n;i++)
         {
             int posNeeded=INT_MAX;
             for(int j=0;j<heaters.size();j++)
             {
                posNeeded=min(posNeeded,abs(houses[i]-heaters[j]));
             }
             maxRadius=max(maxRadius,posNeeded);
         }
      
      return maxRadius;

    }
};

int main()
{
    
    return 0;
}