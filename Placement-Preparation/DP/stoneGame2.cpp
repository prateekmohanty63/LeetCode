#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;

// T(N)=O(2*n*n*M) {alice,i,M,inner for loop}
// S(N)=O(2*n*n)  {alice,i,M}

class Solution {
public:
   
   int aliceMaxScore(vector<int>&piles,int start,int M,bool aliceTurn,unordered_map<string,int>&dp)
   {
       // base case
       int n=piles.size();

       if(start>=n)return 0;

       string a;
       
       if(aliceTurn)
       a+=(to_string(start)+"*"+to_string(M)+"*"+'1');

       else a+=(to_string(start)+"*"+to_string(M)+"*"+'0');

       if(dp.find(a)!=dp.end())return dp[a];
       
       int ans=0;

       if(aliceTurn==1)
       ans=0;

       else ans=INT_MAX;

       int total=0;
       
       // if the turn is even it is alice's choice 

       for(int i=1;i<=2*M;i++)
       {
           if(start+i-1<n)
           {
               total+=piles[start+i-1];

               if(aliceTurn)
               {  
                  // alice's turn
                  ans=max(ans,total+aliceMaxScore(piles,start+i,max(M,i),!aliceTurn,dp));
               }
               else{
                  // bob's turn 
                  ans=min(ans,aliceMaxScore(piles,start+i,max(M,i),!aliceTurn,dp));
               }
           }
           else break;
       }
      
       return dp[a]=ans;

   }

    int stoneGameII(vector<int>& piles) {
        
        unordered_map<string,int>dp;
        return aliceMaxScore(piles,0,1,true,dp);
    }
};

int main()
{
    
    return 0;
}