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

//{ Driver Code Starts.

int main() {
	//code
	
}
// } Driver Code Ends