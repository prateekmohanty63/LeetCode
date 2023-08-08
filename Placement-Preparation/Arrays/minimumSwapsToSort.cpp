//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    
	    // sorting the elements 
	     int n=nums.size();
	    vector<int>sorted=nums;
	    sort(sorted.begin(),sorted.end());
	    
	    unordered_map<int,int>pos;
	    
	    for(int i=0;i<n;i++)
	    {
	        pos[nums[i]]=i;
	    }
	    
	   
	    int res=0;
	    
	    int ptr1=0;
	    int ptr2=0;
	    
	    while(ptr1<n && ptr2<n)
	    {
	        if(nums[ptr1]==sorted[ptr2])
	        {
	            ptr1++;
	            ptr2++;
	        }
	        else{
	           int currPos=pos[sorted[ptr2]];
	           pos[sorted[ptr2]]=ptr2;
	           swap(nums[ptr2],nums[currPos]);
	           pos[nums[currPos]]=currPos;
	           res++;
	           ptr1++;
	           ptr2++;
	           
	        }
	    }
	    return res;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends

int main()
{
    
    return 0;
}