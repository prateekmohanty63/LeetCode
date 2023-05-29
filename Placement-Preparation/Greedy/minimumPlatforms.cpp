#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<climits>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	vector<pair<int,int>>timings;
    	
    	for(int i=0;i<n;i++)
    	{
    	    pair<int,int>pr;
    	    pr.first=dep[i];
    	    pr.second=arr[i];
    	    timings.push_back(pr);
    	}
    	
    	// sorting based on the departure timings
    	sort(timings.begin(),timings.end());
    	
    	unordered_map<int,int>platformStatus;
    	
    	platformStatus[1]=timings[0].first;
    	
    	int count=1;
    	
    	for(int i=1;i<n;i++)
    	{
    	    int flag=0;
    	    int minDiff=INT_MAX;
    	    int platFormAllocated=-1;
    	    
    	    for(auto it:platformStatus)
    	    {
    	        if(it.second<timings[i].second)
    	        {
    	            flag=1;
    	            if(timings[i].second-it.second<minDiff)
    	            {
    	                minDiff=timings[i].second-it.second;
    	                platFormAllocated=it.first;
    	            }
    	        }
    	    }
    	    if(flag==1){
    	        platformStatus[platFormAllocated]=timings[i].first;
    	    }
    	    if(flag==0){
    	        count++;
    	        platformStatus[count]=timings[i].first;
    	    }
    	}
    	return count;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends

int main()
{
    
    return 0;
}