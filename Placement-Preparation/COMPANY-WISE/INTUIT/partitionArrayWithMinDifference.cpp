//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
    
    int solve(int arr[],int &n,int index,int &totalSum,int currSum,vector<vector<int>>&dp)
    {
        // base case
        if(index>=n)
        {
            return abs(currSum-(totalSum-currSum));
        }
        
        // we have the option of taking the element in the current array 
        // or not taking it
        
        //int ans=INT_MAX;
        
        if(dp[index][currSum]!=-1)return dp[index][currSum];
        
        int take=solve(arr,n,index+1,totalSum,currSum+arr[index],dp);
        int notTake=solve(arr,n,index+1,totalSum,currSum,dp);
        
        return dp[index][currSum]=min(take,notTake);
    }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    
	    int sum=0;
	    
	    for(int i=0;i<n;i++)
	    {
	        sum+=arr[i];
	    }
	    
	    vector<vector<int>>dp(n+1,vector<int>(sum,-1));
	    
	    int res=solve(arr,n,0,sum,0,dp);
	    
	    return res;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends

int main()
{
    
    return 0;
}