//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        // code here
        int res=INT_MIN;
        
        vector<int>minVector(n,0);
        vector<int>maxVector(n,0);
        
        // calculating min from left
        minVector[0]=arr[0];
        
        for(int i=1;i<n;i++)
        {
            minVector[i]=min(minVector[i-1],arr[i]);
        }
        
        // calculating max from right
        maxVector[n-1]=arr[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
            maxVector[i]=max(maxVector[i+1],arr[i]);
        }
        
        int leftMin=n-1;
        int rightMin=n-1;
        
        while(leftMin>=0 && rightMin>=0)
        {
            int minim=minVector[leftMin];
            int maxim=maxVector[rightMin];
            
            if(minim<=maxim)
            {
                res=max(res,rightMin-leftMin);
                leftMin--;
            }
            else{
                rightMin--;
            }
        }
        return res;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends