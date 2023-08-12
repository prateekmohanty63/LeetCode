#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
     static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0]==b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        int n=envelopes.size();
        
        // sorting by height & if we encounter same height
        // sort by descending order of width
        sort(envelopes.begin(),envelopes.end(),cmp);

        // e.g. -> env => (3,8) (4,5) (2,1) (2,6) (7,8) (5,3) (5,7)
        // sorted version => (2,6) (2,1) (3,8) (4,5) (5,7) (5,3) (7,8)

         // Now, we only need to care about width
        // So, as of now we only need to look upon v[i][1]
        // [ 6, 1, 8, 5, 7, 3, 8 ]

         vector<int>lis;

         for(int i=0;i<envelopes.size();i++)
         {
             int  ele=envelopes[i][1];

             // finding the index of width , just smaller than the 
             // current width

             int idx=lower_bound(lis.begin(),lis.end(),ele)-lis.begin();

             if(idx>=lis.size())
             {
                 // there is not width smaller than this
                 // we can include this envelope

                 lis.push_back(ele);
             }

             else{
                 // we have a envelope smaller than this
                 // we will replace the smaller width enevlope
                 // with a larger width envelope
                 lis[idx]=ele;
             }
             
         }
   for(auto it:lis)cout<<it<<" ";
    return lis.size();
    }
};

// TLE 

class Solution {
public:
    int solve(vector<vector<int>>&vec,int ind,int prevInd,vector<vector<int>>&dp)
    {
         int n=vec.size();

         if(ind<0)return 0;

         if(dp[ind][prevInd]!=-1)return dp[ind][prevInd];


         if(prevInd==n)
         {
              return dp[ind][prevInd]=max(1+solve(vec,ind-1,ind,dp),solve(vec,ind-1,prevInd,dp));
         }
        
        else{
         int currHeight=vec[ind][0];
         int currWidth=vec[ind][1];

         int lastHeight=vec[prevInd][0];
         int lastWidth=vec[prevInd][1];

         if(currHeight<lastHeight && currWidth<lastWidth)
         {
             // we have the option wether to envelope this index or not
             return  dp[ind][prevInd]=max(1+solve(vec,ind-1,ind,dp),solve(vec,ind-1,prevInd,dp));
         }
         else return  dp[ind][prevInd]=solve(vec,ind-1,prevInd,dp);
        }
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        // sorting the envelopes based on size
       
        sort(envelopes.begin(),envelopes.end());

        int n=envelopes.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));

        int res=solve(envelopes,n-1,n,dp);
        //int res1=solve(tempVec,n-1,n);

        return res;

    }
};


// TLE

class Solution {
public:
    int solve(vector<vector<int>>&vec,int ind,int prevInd)
    {
         int n=vec.size();

         if(ind<0)return 0;


         if(prevInd==n)
         {
              return max(1+solve(vec,ind-1,ind),solve(vec,ind-1,prevInd));
         }
        
        else{
         int currHeight=vec[ind][0];
         int currWidth=vec[ind][1];

         int lastHeight=vec[prevInd][0];
         int lastWidth=vec[prevInd][1];

         if(currHeight<lastHeight && currWidth<lastWidth)
         {
             // we have the option wether to envelope this index or not
             return max(1+solve(vec,ind-1,ind),solve(vec,ind-1,prevInd));
         }
         else return solve(vec,ind-1,prevInd);
        }
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        // sorting the envelopes based on size
       
        sort(envelopes.begin(),envelopes.end());

        int n=envelopes.size();

        int res=solve(envelopes,n-1,n);
        //int res1=solve(tempVec,n-1,n);

        return res;

    }
};

int main()
{
    
    return 0;
}