//{ Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
    

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        // Code here
        vector<int>rightMax(n);
        vector<int>res;
        rightMax[n-1]=a[n-1];
        for(int i=n-2;i>=0;i--)
        {
            rightMax[i]=max(rightMax[i+1],a[i]);
        }
        
        for(int i=0;i<n;i++)
        {
            if(rightMax[i]==a[i])
            {
                res.push_back(a[i]);
            }
        }
        
        return res;
        
    }
};

//{ Driver Code Starts.

int main()
{
   
   
}

// } Driver Code Ends