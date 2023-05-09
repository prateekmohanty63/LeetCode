#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;


class Solution {
public:
   
   int findClosest(vector<int>&heater,int target)
   {
       int left=0;
       int right=heater.size();

       if(target<=heater[0])return heater[0];

       if(target>=heater[heater.size()-1])return heater[heater.size()-1];
     
        int mid=0;
       while(left<right)
       {
           int mid=(left+right)/2;

           if(heater[mid]==target)return heater[mid];

           else if(target>heater[mid])
           {
             if(mid+1<heater.size() && target<heater[mid+1])
             {
                 if(abs(target-heater[mid])<abs(target-heater[mid+1]))return heater[mid];

                 else heater[mid+1];
             }
               left=mid+1;
           }
           else{
               
               if(mid-1>=0 && target>heater[mid-1])
               {
                   if(abs(target-heater[mid])<abs(target-heater[mid-1]))return heater[mid];

                   else return heater[mid-1];
               }
               right=mid;
               
           }
       }
       return heater[mid];
   }

    int findRadius(vector<int>& houses, vector<int>& heaters) {

        int maximRadius=INT_MIN;
       int n=houses.size(); 
       sort(heaters.begin(),heaters.end());

       for(int i=0;i<houses.size();i++)
       {
           int minEle=abs(houses[i]-findClosest(heaters,houses[i]));
           maximRadius=max(maximRadius,minEle);
       }
       return maximRadius;
    }
};


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