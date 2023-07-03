#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int solve(vector<int>&cookies,int k,int index,vector<int>noCookies)
    {
        // base case
        int n=cookies.size();

        if(index>=n)
        {
            int maxim=INT_MIN;
            for(auto it:noCookies)maxim=max(maxim,it);

            return maxim;
        }
        int ans=INT_MAX;

        for(int i=0;i<k;i++)
        {
            noCookies[i]+=cookies[index];
            // explore the other branches of this possibility
            ans=min(ans,solve(cookies,k,index+1,noCookies));

            // now we gave to ith child and explored all the possibility
            // now suppose we give i+1 th child instead of ith child
            noCookies[i]-=cookies[index];
        }
        return ans;
    }
    int distributeCookies(vector<int>& cookies, int k) {
         
         vector<int>noCookies(k,0);
         int res=solve(cookies,k,0,noCookies);

         return res;

    }
};

int main()
{
    
    return 0;
}