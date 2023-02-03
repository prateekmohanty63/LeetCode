#include<iostream>
#include<vector>
#include<climits>
using namespace std;


// TLE (logic correct)
class Solution {
public:
   
   int cost(string colors,vector<int>&time,int i)
   {
       // base case
       
       if(i+1>=colors.length())return 0;

       int price=0;

       if(colors[i]==colors[i+1])
       {
          
               int ptr=i;
               char col=colors[i];
               int maxTime=INT_MIN;

               while(colors[ptr]==col && ptr<colors.length())
               {
                  if(time[ptr]>maxTime)maxTime=time[ptr];

                  price+=time[ptr];
                  ptr++;
               }
               price-=maxTime;

               return price+cost(colors,time,ptr);
          
       }
       else return cost(colors,time,i+1);

   }

    int minCost(string colors, vector<int>& neededTime) {
        
        int res;

        res=cost(colors,neededTime,0);

        return res;
    }
};

int main()
{
    
    return 0;
}