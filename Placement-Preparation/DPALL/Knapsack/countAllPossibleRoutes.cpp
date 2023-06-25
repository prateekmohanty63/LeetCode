#include<iostream>
#include<vector>
using namespace std;


// TLE 
class Solution {
public:
   int mod=1000000007;
   int ans=0;

   void solve(vector<int>&locations,int start,int finish,int fuel)
   {
       // base case
       if(start==finish)(ans++)%mod;

       if(fuel<0)return ;

      int n=locations.size();
     
      for(int i=0;i<n;i++)
      {
          int currCity=locations[i];
          int fuelNeeded=abs(locations[start]-currCity);

          if(currCity!=locations[start] && fuelNeeded<=fuel)
          {
              // we have the option of either going to the city or not going to it
            solve(locations,i,finish,fuel-fuelNeeded);
          }
          
      }
    
   }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        
        

        solve(locations,start,finish,fuel);

        return ans;


    }
};

int main()
{
    
    return 0;
}