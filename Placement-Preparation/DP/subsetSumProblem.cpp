#include<iostream>
#include<vector>

using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
   
   bool isPresent(vector<int>&arr,int sum,int i,vector<vector<int>>&dp)
   {
       // base case
       if(sum==0)return true;
       
       if(sum<0)return false;
       
       if(i<0)return false;
       
       if(dp[sum][i]!=-1)return dp[sum][i];
       // option of choosing or not choosing
       
       return dp[sum][i]=(isPresent(arr,sum-arr[i],i-1,dp) || isPresent(arr,sum,i-1,dp));
       
   }

    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        vector<vector<int>>dp(sum+1,vector<int>(n+1,-1));
        
        return isPresent(arr,sum,n-1,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends

int main()
{
    
    return 0;
}