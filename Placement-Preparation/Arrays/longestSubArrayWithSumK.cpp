//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// T(N)=O(N^2)
// S(N)=O(1)

class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        
        int ans=INT_MIN;
        
        for(int i=0;i<N;i++)
        {
            int sum=A[i];
            if(sum==K)ans=max(ans,1);
            
            for(int j=i+1;j<N;j++)
            {
                sum+=A[j];
                
                if(sum==K)ans=max(ans,j-i+1);
            }
        }
        if(ans==INT_MIN)return 0;
        return ans;
    } 

};


// T(n)=O(n)
// S(n)=O(n)


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        
        int ans=INT_MIN;
       
       
        unordered_map<long long,int>mp;
        
       long long sum=0;
        
        for(int i=0;i<N;i++)
        {
            sum+=A[i];
            
            if(sum==K)ans=max(ans,i+1);
            
            long long req=sum-K;
            if(mp.find(req)!=mp.end()){
            ans=max(ans,i-mp[req]);
            }
            
            if(mp.find(sum)==mp.end())
            mp[sum]=i;
        }
        
        if(ans==INT_MIN)return 0;
        return ans;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends

//{ Driver Code Starts.

int main() {
	//code
	
}
// } Driver Code Ends