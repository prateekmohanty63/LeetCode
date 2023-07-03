#include<iostream>
#include<vector>
#include<climits>
using namespace std;


// T(N)=O((2^N)*(N))
// O(N) is multipled becasue we are checking if all are 0s in the end 
class Solution {
public:
    
    int solve(vector<vector<int>>&req,int index,int count,vector<int>&building)
    {
        int m=req.size();
        
        if(index>=m)
        {
            for(auto it:building)if(it!=0)return 0;   // O(N)

            return count;
        }

        int ans=INT_MIN;

        int from=req[index][0];
        int to=req[index][1];


        building[from]--;
        building[to]++;
      
      // if the current request is accepted
       ans=max(ans,solve(req,index+1,count+1,building));

       building[from]++;
       building[to]--;
      
      // if the current request in not accepted
        ans=max(ans,solve(req,index+1,count,building));

       return ans;

    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        
        vector<int>buildings(n,0);

        int res=solve(requests,0,0,buildings);
       // for(auto it:buildings)cout<<it<<" ";

        return res;

    }
};

int main()
{
    
    return 0;
}