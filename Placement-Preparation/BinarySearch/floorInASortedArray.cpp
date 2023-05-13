//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    
    int binSearch(vector<long long>&vec,long long n,long long &target)
    {
       int start=0;
       int end=n-1;
       int closestInd=-1;
       
       while(start<=end)
       {
           int mid=start+(end-start)/2;
           
           if(vec[mid]==target)return mid;
           
           if(target>vec[mid])
           {
                closestInd=mid;
               start=mid+1;
           }
           else{
              
               end=mid-1;
           }
       }
       return closestInd;
    }
    
    int findFloor(vector<long long> v, long long n, long long x){
        
        // Your code here
        
        int res=binSearch(v,n,x);
        
        return res;
        
    }
};


//{ Driver Code Starts.

int main() {
	
	long long t;
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long x;
	    cin >> x;
	    
	    vector<long long> v;
	    
	    for(long long i = 0;i<n;i++){
	        long long temp;
	        cin >> temp;
	        v.push_back(temp);
	    }
	    Solution obj;
	    cout << obj.findFloor(v, n, x) << endl;
	   
	}
	
	return 0;
}
// } Driver Code Ends