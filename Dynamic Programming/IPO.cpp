#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// solution correct
// giving TLE

class Solution {
public:

   
   
   int maxCapital(vector<int>&profit,vector<int>&capital,int w,int k,int i)
   {
       // base case

       if(i>=capital.size())return 0;

       if(k==0)return 0;
       

       if(capital[i]>w)
       {
           return maxCapital(profit,capital,w,k,i+1);
       }
       else{
           // we have the option of choosing if we want to do the project or not
           return max(profit[i]+maxCapital(profit,capital,w+profit[i],k-1,i+1),maxCapital(profit,capital,w,k,i+1));
          
       }
      
   }

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
       int res=maxCapital(profits,capital,w,k,0);

    
        return w+res;
    }
};

int main()
{
    
    return 0;
}