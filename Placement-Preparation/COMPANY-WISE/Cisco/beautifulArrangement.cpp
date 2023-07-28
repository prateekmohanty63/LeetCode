#include<iostream>
using namespace std;

class Solution {
public:
    int solve(int n,int ind,int mask)
    {
        // base case
      if(ind==n+1){
          return 1;
      }

      int ans=0;
       
       for(int i=1;i<=n;i++)
       {

           if(i%ind==0 || ind%i==0)
           {
              int set=(mask&(1<<i));
              if(set==0)
              {
                  int newMask=(mask|(1<<i));
                  ans+=solve(n,ind+1,newMask);
              }
           }
           
       }
       return ans;

    }
    int countArrangement(int n) {
        int res=solve(n,1,0);
        return res;
    }
};

int main()
{
    
    return 0;
}