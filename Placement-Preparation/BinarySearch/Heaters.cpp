#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;


class Solution {
public:

   int getNearestElement(vector<int>&arr, int n, int target) {
   if (target <= arr[0])
      return arr[0];
   if (target >= arr[n - 1])
      return arr[n - 1];
   int left = 0, right = n, mid = 0;
   while (left < right) {
      mid = left+(right - left) / 2;
      if (arr[mid] == target)
         return arr[mid];
      if (target < arr[mid]) {
         if (mid > 0 && target > arr[mid - 1])
            return getNearest(arr[mid - 1], arr[mid], target);
            right = mid;
      } else {
         if (mid < n - 1 && target < arr[mid + 1])
            return getNearest(arr[mid], arr[mid + 1], target);
         left = mid + 1;
      }
   }
   return arr[mid];
}   

int getNearest(int x, int y, int target) {
   if (abs(target - x) >= abs(y - target))
      return y;
   else
      return x;
}

    int findRadius(vector<int>& houses, vector<int>& heaters) {
        
        int n=houses.size();
        int maxRadius=INT_MIN;

        sort(heaters.begin(),heaters.end());
        
      // cout<<findClosest(heaters,houses[houses.size()-1]);

      for(int i=0;i<houses.size();i++)
      {
          int radiusNeeded=abs(houses[i]-getNearestElement(heaters,heaters.size(),houses[i]));
          maxRadius=max(maxRadius,radiusNeeded);
      }

        
      return maxRadius;

    }
};

int main()
{
    
    return 0;
}