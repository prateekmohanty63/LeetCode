#include<iostream>
#include<vector>

using namespace std;




// T(N)=O(n^2)
// bottom-up 
class Solution{   
public:
   
   bool isPresent(vector<int>&arr,int sum,int i,vector<vector<int>>&dp)
   {
       // base case
       if(sum==0)return true;
       
       if(i<0)return false;
       
       if(dp[sum][i]!=-1)return dp[sum][i];
       // option of choosing or not choosing
       
       if(sum>=arr[i])
       return dp[sum][i]=(isPresent(arr,sum-arr[i],i-1,dp) || isPresent(arr,sum,i-1,dp));
       
       else return dp[sum][i]=isPresent(arr,sum,i-1,dp);
   }
   
   bool isPresentBottomUp(vector<int>&arr,int sum)
   {
       int n=arr.size();
       bool dp[n+1][sum+1];
       
        // initilizing the column 
        for(int i=0;i<=n;i++)
        dp[i][0]=true;
        
        for(int i=1;i<=sum;i++)
        dp[0][i]=false;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(j>=arr[i-1])
                dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
                
                else dp[i][j]=dp[i-1][j];
            }
        }
        
        return dp[n][sum];
   }

    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        vector<vector<bool>>dp(sum+1,vector<bool>(n+1,-1));
        
        return isPresentBottomUp(arr,sum);
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