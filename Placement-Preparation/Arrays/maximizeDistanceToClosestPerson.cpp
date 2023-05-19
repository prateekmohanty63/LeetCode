#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
   int dist(vector<int>&seats,int pos)
   {
       int minDist=INT_MAX;
      for(int i=pos;i>=0;i--)
      {
          if(seats[i]==1)minDist=min(minDist,abs(i-pos));
      }
      for(int i=pos+1;i<seats.size();i++)
      {
          if(seats[i]==1)minDist=min(minDist,abs(i-pos));
      }
      return minDist;
   }
    int maxDistToClosest(vector<int>& seats) {
        
        int n=seats.size();
        int maxDist=INT_MIN;

        for(int i=0;i<n;i++)
        {
           if(seats[i]==0)
           {
               maxDist=max(maxDist,dist(seats,i));
           }
        }
        return maxDist;
    }
};

int main()
{
    
    return 0;
}