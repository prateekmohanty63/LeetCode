#include<iostream>
using namespace std;


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// T(N)=O(Nlog(m))
// S(N)=O(1)
class Solution{
	public:
	int NthRoot(int n, int m)
	{
	    // Code here.
	    int h=m;
	    int l=1;
	    
	    while(l<=h)
	    {
	        int mid=l+(h-l)/2;
	        
	        if(pow(mid,n)==m)return mid;
	        
	        else if(pow(mid,n)<m)
	        {
	            l=mid+1;
	        }
	        else{
	            h=mid-1;
	        }
	    }
	    return -1;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends

int main()
{
    
    return 0;
}