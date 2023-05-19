#include<iostream>
#include<vector>
#include<climits>
using namespace std;


// T(n)=O(n)
// s(n)=o(n)

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        
        int n=seats.size();

        vector<int>closestFromLeft(n,0);
        vector<int>closestFromRight(n,0);

        // checking the closest distance from left 
        if(seats[0]==1)closestFromLeft[0]=0;
        else closestFromLeft[0]=n;

        for(int i=1;i<n;i++)
        {
            if(seats[i]==1)closestFromLeft[i]=i;

            else closestFromLeft[i]=closestFromLeft[i-1];
        }

        // checking the closest from right

        if(seats[n-1]==1)closestFromRight[n-1]=n-1;
        else closestFromRight[n-1]=-1;

        for(int i=n-2;i>=0;i--)
        {
            if(seats[i]==1)closestFromRight[i]=i;

            else closestFromRight[i]=closestFromRight[i+1];
        }

        vector<int>pos(n,0);

        for(int i=0;i<n;i++)
        { 
            int a=abs(closestFromLeft[i]-i);
            int b=abs(i-closestFromRight[i]);
            pos[i]=min(a,b);
        }

        for(auto it:pos)cout<<it<<" ";

        int maximDist=INT_MIN;

        for(auto it:pos)
        {
            maximDist=max(maximDist,it);
        } 
        return maximDist;
    }
};


//  T(n)=O(N^2)
// S(N)=O(1)
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