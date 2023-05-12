#include<iostream>
using namespace std;

//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{


 int firstOccur(int nums[],int n,int target)
   {
       int start=0;
       int end=n-1;
       int minIndex=INT_MAX;
      

       while(start<=end)
       {
           int mid=start+(end-start)/2;

           if(nums[mid]==target)
           {
               minIndex=max(minIndex,mid);

              if(mid==0)return 0;

              else if(mid-1>=0 && nums[mid-1]!=target)return mid;

              else if(mid-1>=0 && nums[mid-1]==target)
              {
                  end=mid-1;
              }
           }
           else if(target>nums[mid])
           {
               start=mid+1;
           }
           else {
               end=mid-1;
           }
       }
       return -1;
   }

   int lastOccur(int nums[],int n,int target)
   {
        int start=0;
       int end=n-1;
       int maxIndex=INT_MIN;
      

       while(start<=end)
       {
           int mid=start+(end-start)/2;

           if(nums[mid]==target)
           {
               maxIndex=max(maxIndex,mid);
               
               if(mid==n-1)return mid;

               else if(mid+1<n && nums[mid+1]!=target)return mid;

               else if(mid+1<n && nums[mid+1]==target)
               start=mid+1;
              
           }
           else if(target>nums[mid])
           {
               start=mid+1;
           }
           else {
               end=mid-1;
           }
       }
       return -1;
   }

    
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	    
	    int minInd=firstOccur(arr,n,x);
	    
	    if(minInd==-1)return 0;
	    
	    int maxInd=lastOccur(arr,n,x);
	    
	    return (maxInd-minInd+1);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends


int main()
{
    
    return 0;
}