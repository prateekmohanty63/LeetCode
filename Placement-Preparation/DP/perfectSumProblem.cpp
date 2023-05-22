#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

// } Driver Code Ends
class Solution{
    
    int numberOfSubsequences(int arr[],int n,int i,int sum,vector<vector<int>>&dp)
    {
        // base case
        int mod=1000000007;
       
        if(sum==0)return 1;
         if(i>=n)return 0;
        
        if(dp[i][sum]!=-1)return dp[i][sum];
        if(arr[i]<=sum)
        {
            return dp[i][sum]=((numberOfSubsequences(arr,n,i+1,sum-arr[i],dp))%mod+(numberOfSubsequences(arr,n,i+1,sum,dp))%mod)%mod;
        }
        else{
            return dp[i][sum]=numberOfSubsequences(arr,n,i+1,sum,dp)%mod;
        }
    
    }

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
         int mod=1000000007;
        int numberOfZeros=0;
        int k=0;
        int arr1[n];
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        for(int i=0;i<n;i++)
        {
            if(arr[i]!=0)arr1[k++]=arr[i];
            
            else numberOfZeros++;
        }
        
        return pow(2,numberOfZeros)*numberOfSubsequences(arr1,k,0,sum,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends


int main()
{
    
    return 0;
}