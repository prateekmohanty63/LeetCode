#include<iostream>
using namespace std;



// } Driver Code Ends
class Solution{
  
  int minimPartition(int arr[],int n,int sumCalculated,int sumTotal,int i,vector<vector<int>>&dp)
  {
       
       if(i==n-1)
       {
           return abs((sumTotal-sumCalculated)-sumCalculated);
       }
       
       if(dp[i][sumCalculated]!=-1)return dp[i][sumCalculated];
       
       // we have the option either we take the element or we dont take the element 
       
       return dp[i][sumCalculated]=min(minimPartition(arr,n,sumCalculated+arr[i],sumTotal,i+1,dp),minimPartition(arr,n,sumCalculated,sumTotal,i+1,dp));
       
  } 
   

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0;
	    for(int i=0;i<n;i++)sum+=arr[i];
	    
	    vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
	    
	     return minimPartition(arr,n,0,sum,0,dp);
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