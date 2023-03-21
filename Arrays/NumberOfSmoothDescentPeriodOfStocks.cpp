#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {

      int n=prices.size();  

      long long res=n;

      for(int i=0;i<n-1;i++)
      {
         if(prices[i]-prices[i+1]==1)
         {
             int start=i;
             int end=i+1;

             while(end+1<n && prices[end]-prices[end+1]==1)
             {
                 end++;
             }

             long long count=(end-start+1);
             res+=(count*(count-1)/2);
             cout<<count;
             i=end;
         }
      } 
      return res;
    }
};

int main()
{
    
    return 0;
}