#include<iostream>
#include<vector>
using namespace std;


// T(N)=O(N^2)
// S(N)=O(N^2)

class Solution {
public:
   int mod=1000000007;

   int solve(vector<int>&locations,int current,int finish,int fuel,vector<vector<int>>&dp)
   {
       if(fuel<0)return 0;

       int n=locations.size();

       int ans=0;

       if(dp[current][fuel]!=-1)return dp[current][fuel];

       if(current==finish)ans++;

       for(int next=0;next<n;next++)
       {
           if(current!=next){
               int fuelNeeded=abs(locations[current]-locations[next]);
           ans=(ans%mod+solve(locations,next,finish,fuel-fuelNeeded,dp)%mod)%mod;
           }
       }
       return dp[current][fuel]=ans%mod;
   }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        
        int n=locations.size();
         vector<vector<int>>dp(n,vector<int>(fuel+1,-1));
        return (solve(locations,start,finish,fuel,dp))%mod;


    }
};


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