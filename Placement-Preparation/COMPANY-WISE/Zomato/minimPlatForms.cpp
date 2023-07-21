//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	
    	
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	
    	int res=0;
    	int count=0;
    	
    	int ptr1=0;
    	int ptr2=0;
    	
    	while(ptr1<n)
    	{
    	    if(arr[ptr1]>dep[ptr2])
    	   {
    	       count--;
    	       ptr2++;
    	   }
    	 
    	   count++;
    	   res=max(res,count);
    	  
    	   ptr1++;
    	}
    	
    	return res;
    }
};



// } Driver Code Ends