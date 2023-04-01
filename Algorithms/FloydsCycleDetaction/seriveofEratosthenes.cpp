#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
  
  int noPrime(int n)
  {
      vector<int>vec(n+1,0);

      for(int i=2;i*i<n;i++)
      {
          if(vec[i]==0)
          {
              for(int j=i*i;j<=n;j+=i)
              {
                  vec[j]=-1;
              }
          }
          else continue;
      }

     int count=0;
      for(int i=2;i<n;i++)
      {
          if(vec[i]==0)count++;
      }
      return count;
  }

    int countPrimes(int n) {
        
        int res=noPrime(n);

        return res;
    }
};

int main()
{
    
    return 0;
}